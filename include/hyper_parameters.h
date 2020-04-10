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

    void create_weights();
    void update_weights();
    std::vector<std::vector<double>> weights() const; // Get whole weight network "matrix"
    float learning_rate() const;

private:
    std::vector<std::vector<double>> _weights;
    std::vector<int> _neurons_per_layer;
    float _learning_rate;
};

#endif