#include <iostream>
#include <algorithm>

#include "hyper_parameters.h"
#include "weight_initialization.h"

HyperParameters::HyperParameters(const std::initializer_list<int> &layer_settings, const float &learning_rate_setting)
{
    _neurons_per_layer = layer_settings;
    _learning_rate = learning_rate_setting;
    create_weights();
}

std::vector<std::vector<double>> HyperParameters::weights() const
{
    return _weights;
}

void HyperParameters::create_weights()
{
    int weight_layers = _neurons_per_layer.size() - 1;
    _weights.resize(weight_layers);

    for (int i = 0; i < weight_layers; i++)
    {
        _weights[i].resize(_neurons_per_layer[i] * _neurons_per_layer[i + 1]);
        std::generate(_weights[i].begin(), _weights[i].end(), WeightInitialization::weight_generator_simple(_neurons_per_layer[i]));
    }
}

void HyperParameters::update_weights() {

}

float HyperParameters::learning_rate() const
{
    return _learning_rate;
}
