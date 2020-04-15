#include <iostream>
#include <algorithm>

#include "hyper_parameters.h"
#include "weight_initialization.h"

HyperParameters::HyperParameters(const std::initializer_list<int> &layer_settings, const int &batch_size, const int &epochs, const float &learning_rate_setting)
{
    _neurons_per_layer = layer_settings;
    _batch_size = batch_size;
    _epochs = epochs;
    _learning_rate = learning_rate_setting;
    create_weights();
}

std::vector<WeightMatrices> HyperParameters::weights() const
{
    return _weights;
}

void HyperParameters::create_weights()
{
    int weight_layers = _neurons_per_layer.size() - 1; // Calculate the required number of weight matrices
    _weights.resize(weight_layers);                    // Resize the struct that contains the weight matrices

    for (int i = 0; i < weight_layers; i++)
    {
        _weights[i].layer_weight_matrix.resize(_neurons_per_layer[i]); // Resize the 'first' vector of vectors

        for (int j = 0; j < _neurons_per_layer[i+1]; j++)
        {
            _weights[i].layer_weight_matrix[j].resize(_neurons_per_layer[i + 1]); // Resize the 'second' vector of vectors
            std::generate(_weights[i].layer_weight_matrix[j].begin(), _weights[i].layer_weight_matrix[j].end(), WeightInitialization::weight_generator_simple(_neurons_per_layer[i]));
        }
    }
}

void HyperParameters::update_weights() {

}

std::vector<int> HyperParameters::neurons_per_layer() const
{
    return _neurons_per_layer;
}

int HyperParameters::batch_size() const
{
    return _batch_size;
}

int HyperParameters::epochs() const
{
    return _epochs;
}

float HyperParameters::learning_rate() const
{
    return _learning_rate;
}
