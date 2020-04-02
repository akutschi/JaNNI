#include <iostream>
#include <string>
#include <chrono>

#include "execution_time.h"


void ExecutionTime::set_start_time() {
    t_start = std::chrono::system_clock::now();
}

void ExecutionTime::set_end_time() {
    t_end = std::chrono::system_clock::now();
}

void ExecutionTime::duration_time() {
    std::cout << "Execution time: " << std::chrono::duration_cast<std::chrono::seconds>(t_end - t_start).count() << " seconds\n" << std::endl;
}
