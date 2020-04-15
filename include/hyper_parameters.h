#ifndef HYPER_PARAMETERS_H
#define HYPER_PARAMETERS_H

#include <vector>

struct WeightMatrices
{
    std::vector<std::vector<double>> layer_weight_matrix; // Stores the weight matrix between two layers
};

class HyperParameters
{
public:
    // Constructor
    // Required number of layer and number of neurons per layer,
    // this includes input and output layer
    HyperParameters(const std::initializer_list<int> &, const int &, const int &, const float &);

    void create_weights();
    void update_weights();
    std::vector<WeightMatrices> weights() const; // Get whole weight network "matrix"
    std::vector<int> neurons_per_layer() const;
    float learning_rate() const;
    int batch_size() const;
    int epochs() const;

private:
    std::vector<WeightMatrices> _weights;
    std::vector<int> _neurons_per_layer;
    float _learning_rate;
    int _batch_size;
    int _epochs;
};

#endif