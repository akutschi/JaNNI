#include "run_mnist.h"

#include <iostream>

RunMNIST::RunMNIST(const std::string &training_data_path,
                   const std::string &training_label_path,
                   const std::string &test_data_path,
                   const std::string &test_label_path,
                   const std::initializer_list<int> &layer_settings,
                   const int &batch_size,
                   const int &epochs,
                   const float &learning_rate)
    : RunCreator::RunCreator(training_data_path,
                             training_label_path,
                             test_data_path, test_label_path,
                             layer_settings,
                             batch_size,
                             epochs,
                             learning_rate)
{
}

void RunMNIST::forward_propagation()
{
    // Define function for forward propagation
}

void RunMNIST::calculate_loss()
{
    // Define function for loss calculation
}

void RunMNIST::back_propagation()
{
    // Define function for back propagation
}

void RunMNIST::training()
{
}

void RunMNIST::test()
{
}
