#include <iostream>
#include <algorithm>

#include "hyper_parameters.h"
#include "weight_initialization.h"

HyperParameters::HyperParameters(const std::initializer_list<int> &layer_settings, const float &learning_rate_setting)
{
    neurons_per_layer_ = layer_settings;
    learning_rate_ = learning_rate_setting;
    create_weight_network();
}

std::vector<std::vector<double>> HyperParameters::get_weight_network() const
{
    return weights_;
}

void HyperParameters::create_weight_network()
{
    int weight_layers = neurons_per_layer_.size() - 1;
    weights_.resize(weight_layers);

    for (int i = 0; i < weight_layers; i++)
    {
        weights_[i].resize(neurons_per_layer_[i] * neurons_per_layer_[i + 1]);
        std::generate(weights_[i].begin(), weights_[i].end(), WeightInitialization::weight_generator_simple(neurons_per_layer_[i]));
    }
}

float HyperParameters::get_learning_rate()
{
    return learning_rate_;
}
