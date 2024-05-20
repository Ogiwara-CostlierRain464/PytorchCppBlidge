cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# Project Name
project(PytorchCppBridge)

# Find Package
# NOTE: specify path of libtorch by 
# -DCMAKE_PREFIX_PATH="$(python -c 'import torch.utils; print(torch.utils.cmake_prefix_path)')"
find_package(Torch REQUIRED)
set(CMAKE_BUILD_TYPE Debug)


# Create Executable File
add_library(ogiLib SHARED src/share.cpp)
set_property(TARGET ogiLib PROPERTY CXX_STANDARD 17)
target_include_directories(ogiLib PRIVATE ${Python3_INCLUDE_DIRS})
target_link_libraries(ogiLib ${TORCH_LIBRARIES} )

# Suppress prefix "lib" because Python does not allow this prefix
set_target_properties(ogiLib PROPERTIES PREFIX "")



