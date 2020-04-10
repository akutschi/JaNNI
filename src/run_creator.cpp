#include "run_creator.h"
#include "hyper_parameters.h"
#include "mnist_data.h"

#include <iostream>

RunCreator::RunCreator(const std::string &training_data_path,
                       const std::string &training_label_path,
                       const std::string &test_data_path,
                       const std::string &test_label_path,
                       const std::initializer_list<int> &layer_settings,
                       const float &learning_rate)
{
    setup_training_data_set(training_data_path, training_label_path);
    setup_hyper_parameters(layer_settings, learning_rate);
    setup_test_data_set(test_data_path, test_label_path);
    std::cout << mnist_training_data[23].data[120] << std::endl;
    std::cout << training_label_magic_dimensions[0] << std::endl;
    std::cout << learning_rate_ << std::endl;
    std::cout << weights[1][23] << std::endl;
}

void RunCreator::setup_training_data_set(const std::string &data_path, const std::string &label_path)
{
    MNISTDataSet training_set(data_path, label_path);
    mnist_training_data = std::move(training_set.mnist_data());
    training_data_magic_number = std::move(training_set.data_magic_values());
    training_data_magic_dimensions = std::move(training_set.data_dimension_values());
    training_label_magic_number = std::move(training_set.label_magic_values());
    training_label_magic_dimensions = std::move(training_set.label_dimension_values());
}

void RunCreator::setup_hyper_parameters(const std::initializer_list<int> &layer_settings, const float &learning_rate)
{
    HyperParameters parameters(layer_settings, learning_rate);
    weights = std::move(parameters.weights());
    learning_rate_ = parameters.learning_rate();
}

void RunCreator::setup_test_data_set(const std::string &data_path, const std::string &label_path)
{
    MNISTDataSet test_set(data_path, label_path);
    mnist_test_data = std::move(test_set.mnist_data());
    test_data_magic_number = std::move(test_set.data_magic_values());
    test_data_magic_dimensions = std::move(test_set.data_dimension_values());
    test_label_magic_number = std::move(test_set.label_magic_values());
    test_label_magic_dimensions = std::move(test_set.label_dimension_values());
}