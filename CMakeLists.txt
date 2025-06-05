cmake_minimum_required(VERSION 3.30)
cmake_policy(SET CMP0057 NEW)

project(PyBind11Log)

include_directories(include)
option(PyBind11Log_BUILD_TESTS OFF)

find_package(Python3 COMPONENTS Interpreter Development)
find_package(Python COMPONENTS Interpreter Development)
find_package(pybind11 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_library(pybind11_log SHARED src/pybind11_log.cpp)
target_sources(pybind11_log PUBLIC FILE_SET HEADERS TYPE HEADERS BASE_DIRS src FILES
        src/pybind11_log.h
)
target_link_libraries(pybind11_log PUBLIC spdlog::spdlog_header_only PRIVATE pybind11::pybind11)

if (PyBind11Log_BUILD_TESTS)
    include(CTest)
    pybind11_add_module(pybind11_log_test tests/pybind11_log_test.cpp)
    target_link_libraries(pybind11_log_test PRIVATE pybind11_log spdlog::spdlog_header_only pybind11::pybind11)
    add_test(NAME log_test COMMAND ${Python_INTERPRETER} "${PROJECT_SOURCE_DIR}/tests/log_test.py")
    set_property(TEST log_test PROPERTY WILL_FAIL TRUE)
endif()
