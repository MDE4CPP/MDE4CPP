#include "helper/TestSuiteTimeHelper.hpp"
#include <chrono>

std::chrono::time_point<std::chrono::high_resolution_clock> TestSuiteTimeHelper::_TimeAtTestBegin = std::chrono::time_point<std::chrono::high_resolution_clock>::min();
std::chrono::time_point<std::chrono::high_resolution_clock> TestSuiteTimeHelper::_TimeAtTestEnd = std::chrono::time_point<std::chrono::high_resolution_clock>::min();
