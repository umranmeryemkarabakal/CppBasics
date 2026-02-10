cmake_minimum_required(VERSION 3.14)
project(S04_vision_quality_controller LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- PYBIND11 AYARI (YEREL) ---
add_subdirectory(vendor/pybind11)

# --- OPENCV AYARI ---
find_package(OpenCV REQUIRED)

message(STATUS "OpenCV Version: ${OpenCV_VERSION}")

# --- MODÜL OLUŞTURMA ---
pybind11_add_module(S04_vision_quality_controller S04_vision_quality_controller.cpp)

# --- BAĞLAMA (LINK) ---
target_link_libraries(S04_vision_quality_controller PRIVATE ${OpenCV_LIBS})