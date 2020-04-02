#ifndef EXECUTION_TIME_H
#define EXECUTION_TIME_H

#include <chrono>


class ExecutionTime {
public:
    void set_start_time();
    void set_end_time();
    void duration_time();
private:
    std::chrono::high_resolution_clock::time_point t_start;
    std::chrono::high_resolution_clock::time_point t_end;
};

#endif