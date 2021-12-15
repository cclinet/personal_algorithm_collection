cmake_minimum_required(VERSION 3.21)
project(compute_with_python C)

set(CMAKE_C_STANDARD 99)
find_package(PythonLibs REQUIRED)

add_executable(compute_with_python main.c)

include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(compute_with_python ${PYTHON_LIBRARIES})