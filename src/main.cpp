#include <iostream>
#include <chrono> // NOTE: required for sleep
#include <thread> // NOTE: required for sleep

#include "print_info.h"
#include "execution_time.h"


int main() {
    PrintInfo output_messages;

    output_messages.welcome_message();

    ExecutionTime timer_training;
    timer_training.set_start_time();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer_training.set_end_time();
    timer_training.duration_time();

    ExecutionTime timer_testing;
    timer_testing.set_start_time();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer_testing.set_end_time();
    timer_testing.duration_time();
    
    output_messages.done_message();

    return 0;
}