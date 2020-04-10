#ifndef EXECUTION_TIME_H
#define EXECUTION_TIME_H

#include <chrono>

class ExecutionTime
{
public:
    void start_time();
    void end_time();
    void duration_time();

private:
    std::chrono::high_resolution_clock::time_point _t_start;
    std::chrono::high_resolution_clock::time_point _t_end;
};

#endif