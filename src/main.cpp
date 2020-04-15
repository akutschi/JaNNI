#include <iostream>

#include "print_info.h"
#include "execution_time.h"
#include "run_mnist.h"

int main()
{
    PrintInfo output_messages;

    output_messages.welcome_message();

    output_messages.proceed_confirmation();

    ExecutionTime timer_setup;
    timer_setup.start_time();
    RunMNIST run("../mnist_data/train-images-idx3-ubyte", "../mnist_data/train-labels-idx1-ubyte", // Training data set
                 "../mnist_data/t10k-images-idx3-ubyte", "../mnist_data/t10k-labels-idx1-ubyte",   // Test data set
                 {768, 200, 40, 10},                                                               // Layer settings, nodes per layer
                 10,                                                                               // Batch size
                 1,                                                                                // Epochs
                 0.05);                                                                            // Learning rate
    run.show_summary();
    timer_setup.end_time();
    timer_setup.duration_time();

    output_messages.proceed_confirmation();

    output_messages.done_message();

    return 0;
}