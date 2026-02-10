#include <opencv2/opencv.hpp>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

namespace py = pybind11;
using namespace cv;
using namespace std;


// TYPE CASTER 
namespace pybind11 { namespace detail {

template <> struct type_caster<cv::Mat> {
    public:
        PYBIND11_TYPE_CASTER(cv::Mat, _("numpy.ndarray"));

        bool load(handle src, bool) {
            if (!py::isinstance<py::array>(src)) return false;
            auto buf = py::array::ensure(src); // Bellek güvenliğini sağlar
            if (!buf) return false;

            int ndims = buf.ndim();
            if (ndims < 2 || ndims > 3) return false;

            int dtype;
            if (buf.dtype().is(py::dtype::of<uint8_t>())) { dtype = CV_8U; }
            else if (buf.dtype().is(py::dtype::of<float>())) { dtype = CV_32F; }
            else if (buf.dtype().is(py::dtype::of<double>())) { dtype = CV_64F; }
            else { return false; }

            std::vector<int> shape(ndims);
            for(int i = 0; i < ndims; i++) shape[i] = buf.shape(i);

            int channels = (ndims == 3) ? shape[2] : 1;
            value = cv::Mat(shape[0], shape[1], CV_MAKETYPE(dtype, channels), buf.mutable_data());
            return true;
        }

        static handle cast(const cv::Mat& mat, return_value_policy, handle) {
            std::string format = py::format_descriptor<unsigned char>::format();
            size_t elemsize = sizeof(unsigned char);
            int ndim = (mat.channels() > 1) ? 3 : 2;
            std::vector<size_t> shape(ndim);
            shape[0] = mat.rows;
            shape[1] = mat.cols;
            if (ndim == 3) shape[2] = mat.channels();

            std::vector<size_t> strides(ndim);
            strides[0] = mat.step[0];
            strides[1] = mat.step[1];
            if (ndim == 3) strides[2] = mat.elemSize1();

            return py::array(py::buffer_info(
                mat.data, elemsize, format, ndim, shape, strides
            )).release();
        }
};
}} // namespace pybind11::detail


// Yardımcı Gamma Fonksiyonu
void applyGamma(Mat& channel, double gamma) {
    Mat lut(1, 256, CV_8U);
    uchar* ptr = lut.ptr();
    for (int i = 0; i < 256; ++i) {
        ptr[i] = saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);
    }
    LUT(channel, lut, channel);
}

// ANA FONKSİYON
cv::Mat analyze_image_and_apply_methods(cv::Mat img) {
    
    // Type Caster sayesinde boş resim kontrolünü burada yapabiliriz
    if (img.empty()) {
        cerr << "Hata: Gelen resim bos!" << endl;
        return cv::Mat(); 
    }

    // Orijinal veriyi bozmamak için klonluyoruz
    Mat processed_img = img.clone();

    // --- ANALİZ ---
    Mat gray_img, hsv_img;
    
    if (img.channels() == 3) {
        cvtColor(img, gray_img, COLOR_BGR2GRAY);
        cvtColor(img, hsv_img, COLOR_BGR2HSV);
    } else {
        gray_img = img.clone();
        cvtColor(img, hsv_img, COLOR_GRAY2BGR);
        cvtColor(hsv_img, hsv_img, COLOR_BGR2HSV);
    }

    vector<Mat> hsv_channels;
    split(hsv_img, hsv_channels);
    Mat v_channel = hsv_channels[2];

    // İstatistikler
    Scalar mean_gray = mean(gray_img);
    Scalar mean_v = mean(v_channel);
    double mean_brightness_gray = mean_gray[0];
    double mean_brightness_v = mean_v[0];

    Scalar mean_unused, stddev_scalar;
    meanStdDev(gray_img, mean_unused, stddev_scalar);
    double contrast_std = stddev_scalar[0];

    Mat laplacian;
    Laplacian(gray_img, laplacian, CV_64F);
    Scalar mean_lap, stddev_lap;
    meanStdDev(laplacian, mean_lap, stddev_lap);
    double blur_score = stddev_lap[0] * stddev_lap[0];

    Mat median_filtered_gray, diff_img;
    medianBlur(gray_img, median_filtered_gray, 3);
    absdiff(gray_img, median_filtered_gray, diff_img);
    Scalar mean_diff = mean(diff_img);
    double noise_score = mean_diff[0];

    // Eşikler
    bool is_low_light = (mean_brightness_gray < 50 || mean_brightness_v < 60);
    bool is_overexposed = (mean_brightness_gray > 200 || mean_brightness_v > 220);
    bool is_low_contrast = (contrast_std < 40);
    bool is_noisy = (noise_score > 5);

    // Sadece 3 kanallı (renkli) resimlerde düzeltme
    if (processed_img.channels() == 3) {
        
        if (is_noisy) {
            medianBlur(processed_img, processed_img, 5);
        }

        if (is_low_light) {
            Mat hsv_proc;
            cvtColor(processed_img, hsv_proc, COLOR_BGR2HSV);
            vector<Mat> channels;
            split(hsv_proc, channels);
            
            Ptr<CLAHE> clahe = createCLAHE(2.0, Size(8, 8));
            clahe->apply(channels[2], channels[2]);
            applyGamma(channels[2], 0.8);

            merge(channels, hsv_proc);
            cvtColor(hsv_proc, processed_img, COLOR_HSV2BGR);

        } else if (is_overexposed) {
            vector<Mat> bgr_channels;
            split(processed_img, bgr_channels);
            for(int i=0; i<3; i++) applyGamma(bgr_channels[i], 1.2);
            merge(bgr_channels, processed_img);

            Mat hsv_proc;
            cvtColor(processed_img, hsv_proc, COLOR_BGR2HSV);
            vector<Mat> channels;
            split(hsv_proc, channels);

            subtract(channels[2], Scalar(50), channels[2]);
            channels[2].convertTo(channels[2], -1, 0.7, 0); 

            merge(channels, hsv_proc);
            cvtColor(hsv_proc, processed_img, COLOR_HSV2BGR);

        } else if (is_low_contrast) {
            Mat hsv_proc;
            cvtColor(processed_img, hsv_proc, COLOR_BGR2HSV);
            vector<Mat> channels;
            split(hsv_proc, channels);

            Ptr<CLAHE> clahe = createCLAHE(2.0, Size(8, 8));
            clahe->apply(channels[2], channels[2]);

            merge(channels, hsv_proc);
            cvtColor(hsv_proc, processed_img, COLOR_HSV2BGR);
        }
    }

    return processed_img; // Type caster bunu otomatik NumPy'a çevirecek
}

PYBIND11_MODULE(S04_vision_quality_controller, m) {
    m.doc() = "Görüntü Kalite Kontrol Modülü (NumPy Type Caster ile)";
    m.def("analyze_image_and_apply_methods", &analyze_image_and_apply_methods, "Resmi analiz eder ve iyileştirir.");
}