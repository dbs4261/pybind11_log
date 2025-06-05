#pragma once

#include <string>


namespace pybind11_log {

/// Initialize a multi-threaded logger
void init_mt(const std::string& logger_name);

/// Initialize a single-threaded logger
void init_st(const std::string& logger_name);

}  // namespace pybind11_log
