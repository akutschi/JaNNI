#ifndef RUN_CREATOR_H
#define RUN_CREATOR_H

#include <string>
#include <vector>

#include "mnist_data.h"

class RunCreator
{
public:
    RunCreator(const std::string &,
               const std::string &,
               const std::string &,
               const std::string &,
               const std::initializer_list<int> &,
               const float &);

    void setup_training_data_set(const std::string &, const std::string &);
    void setup_hyper_parameters(const std::initializer_list<int> &, const float &);
    void setup_test_data_set(const std::string &, const std::string &);

private:
    std::vector<MNISTDataEntry> mnist_training_data;
    std::vector<int> training_data_magic_number;
    std::vector<int> training_data_magic_dimensions;
    std::vector<int> training_label_magic_number;
    std::vector<int> training_label_magic_dimensions;
    std::vector<MNISTDataEntry> mnist_test_data;
    std::vector<int> test_data_magic_number;
    std::vector<int> test_data_magic_dimensions;
    std::vector<int> test_label_magic_number;
    std::vector<int> test_label_magic_dimensions;
    std::vector<std::vector<double>> weights;
    float learning_rate_;
};

#endif