cmake_minimum_required(VERSION 3.16)

project(QC)

# Requires C++20.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS
    "-Werror -Wall -Wextra -O2 -finline-functions -march=native"
)

# Install inside the build directory.
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

include_directories(.)

enable_testing()

add_subdirectory(test)
