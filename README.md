# CppBasics

<p>
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white" alt="CMake" />
  <img src="https://img.shields.io/badge/pybind11-20232A?style=for-the-badge" alt="pybind11" />
  <img src="https://img.shields.io/badge/OpenCV-5C3EE8?style=for-the-badge&logo=opencv&logoColor=white" alt="OpenCV" />
</p>

## Overview

C++ fundamentals (arrays, control flow, functions, pointers, writing files, pattern printing) and a small project that compiles an OpenCV-based image quality module to a Python extension with pybind11.

**Quick start:** `g++ -std=c++17 array.cpp -o array && ./array`

## Proje hakkında

C++ temelleri ve pybind11 ile C++ kodunu Python modülüne dönüştüren bir OpenCV projesi.

## İçerik

- `cpp_giris.cpp`, `control_donguler.cpp`, `array.cpp`, `functions.cpp`: temel yapı, döngüler, diziler, fonksiyonlar
- `pointers.cpp`, `pointers_fuction.cpp`: işaretçiler
- `file.cpp`: `ofstream` ile dosyaya yazma
- `ters_ucgen.cpp`, `yıildiz_matris.cpp`: desen yazdırma
- `cpp_to_pyd_debug/`: `analyze_image_and_apply_methods` fonksiyonunu pybind11 ile Python'a açan OpenCV görüntü kalite modülü (CMake)

## Kurulum ve çalıştırma

**Temel örnekler:**

```bash
g++ -std=c++17 functions.cpp -o functions
./functions
```

**pybind11 + OpenCV modülü** (OpenCV kurulu olmalı):

```bash
cd cpp_to_pyd_debug
cmake -S . -B build
cmake --build build --config Release
```

Derlenen modül Python'dan `import S04_vision_quality_controller` ile kullanılır.

## Dosya yapısı

```text
CppBasics/
├── cpp_to_pyd_debug/
│   ├── vendor/                      pybind11 ve pybind11-opencv
│   ├── CMakeLists.txt
│   ├── S04_vision_quality_controller.cpp
│   └── pybind11_opencv_converter.hpp
├── array.cpp
├── control_donguler.cpp
├── cpp_giris.cpp
├── file.cpp
├── functions.cpp
├── main.cpp
├── pointers.cpp
├── pointers_fuction.cpp
├── ters_ucgen.cpp
└── yıildiz_matris.cpp
```

## Notlar

- Derleme çıktıları (`.exe`, `build/`, `.dll`) depodan çıkarıldı; kaynak koddan yeniden üretilebilir.
- `cpp_to_pyd_debug/vendor/` altında pybind11 ve pybind11-opencv kaynakları bulunur.
