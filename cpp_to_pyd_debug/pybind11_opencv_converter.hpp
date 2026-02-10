#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <opencv2/opencv.hpp>

namespace py = pybind11;

namespace pybind11 { namespace detail {

template <> struct type_caster<cv::Mat> {
public:
    PYBIND11_TYPE_CASTER(cv::Mat, _("numpy.ndarray"));

    // numpy -> cv::Mat
    bool load(handle src, bool) {
        py::array arr = py::reinterpret_borrow<py::array>(src);
        py::buffer_info info = arr.request();

        if (info.ndim < 2 || info.ndim > 3)
            return false;

        int height   = static_cast<int>(info.shape[0]);
        int width    = static_cast<int>(info.shape[1]);
        int channels = (info.ndim == 3) ? static_cast<int>(info.shape[2]) : 1;

        int depth;
        if (py::isinstance<py::array_t<uint8_t>>(arr)) {
            depth = CV_8U;
        } else if (py::isinstance<py::array_t<float>>(arr)) {
            depth = CV_32F;
        } else {
            return false; // desteklenmeyen tip
        }

        int cv_type = CV_MAKETYPE(depth, channels);
        cv::Mat mat(height, width, cv_type);

        size_t row_bytes = width * channels * ((depth == CV_8U) ? sizeof(uint8_t) : sizeof(float));
        for (int i = 0; i < height; ++i) {
            memcpy(mat.ptr(i), static_cast<uint8_t*>(info.ptr) + i * row_bytes, row_bytes);
        }

        value = mat;
        return true;
    }

    // cv::Mat -> numpy
    static handle cast(const cv::Mat &mat, return_value_policy, handle) {
        int depth = mat.depth();
        int channels = mat.channels();

        py::dtype dtype;
        if (depth == CV_8U) {
            dtype = py::dtype::of<uint8_t>();
        } else if (depth == CV_32F) {
            dtype = py::dtype::of<float>();
        } else {
            throw std::runtime_error("Unsupported cv::Mat depth");
        }

        std::vector<size_t> shape;
        if (channels == 1) {
            shape = { (size_t)mat.rows, (size_t)mat.cols };
        } else {
            shape = { (size_t)mat.rows, (size_t)mat.cols, (size_t)channels };
        }

        std::vector<size_t> strides;
        if (channels == 1) {
            strides = { (size_t)mat.step, (size_t)mat.elemSize() };
        } else {
            strides = { (size_t)mat.step, (size_t)(channels * mat.elemSize1()), (size_t)mat.elemSize1() };
        }

        return py::array(dtype, shape, strides, mat.data).release();
    }
};

}} // namespace pybind11::detail

inline void init_opencv_numpy() {}
