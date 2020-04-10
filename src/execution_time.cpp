#include <iostream>
#include <string>
#include <chrono>

#include "execution_time.h"

void ExecutionTime::start_time()
{
    _t_start = std::chrono::system_clock::now();
}

void ExecutionTime::end_time()
{
    _t_end = std::chrono::system_clock::now();
}

void ExecutionTime::duration_time()
{
    std::cout << "Execution time: " << std::chrono::duration_cast<std::chrono::seconds>(_t_end - _t_start).count() << " seconds\n"
              << std::endl;
}
