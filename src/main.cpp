#include <iostream>

#include "print_info.h"
#include "execution_time.h"
#include "run_creator.h"

int main()
{   
    PrintInfo output_messages;

    output_messages.welcome_message();

    output_messages.proceed_confirmation();
    
    ExecutionTime timer_setup;
    timer_setup.set_start_time();
    RunCreator run("../mnist_data/train-images-idx3-ubyte", "../mnist_data/train-labels-idx1-ubyte", // Training data set
                   "../mnist_data/t10k-images-idx3-ubyte", "../mnist_data/t10k-labels-idx1-ubyte",   // Test data set
                   {768, 200, 40, 10},                                                               // Layer settings, nodes per layer
                   0.05);                                                                            // Learning rate
    timer_setup.set_end_time();
    timer_setup.duration_time();

    output_messages.done_message();

    return 0;
}