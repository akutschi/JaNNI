#ifndef HYPER_PARAMETERS_H
#define HYPER_PARAMETERS_H

#include <vector>

class HyperParameters
{
public:
    // Constructor
    // Required number of layer and number of neurons per layer,
    // this includes input and output layer
    // e.g. HyperParameters(768, 90 60 50, 10)
    HyperParameters(const std::initializer_list<int> &, const float &);

    void create_weight_network();
    void update_weight_network();
    std::vector<std::vector<double>> get_weight_network() const; // Get whole weight network "matrix"
    float get_learning_rate();

private:
    std::vector<std::vector<double>> weights_;
    std::vector<int> neurons_per_layer_;
    float learning_rate_;
};

#endif