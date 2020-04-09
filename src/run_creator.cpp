#include "run_creator.h"
#include "hyper_parameters.h"
#include "mnist_data.h"

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
}

void RunCreator::setup_training_data_set(const std::string &data_path, const std::string &label_path)
{
    MNISTDataSet training_set(data_path, label_path);
}

void RunCreator::setup_hyper_parameters(const std::initializer_list<int> &, const float &)
{
}

void RunCreator::setup_test_data_set(const std::string &data_path, const std::string &label_path)
{
    MNISTDataSet test_set(data_path, label_path);
}