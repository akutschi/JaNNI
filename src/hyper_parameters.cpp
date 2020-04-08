#include <iostream>
#include <algorithm>

#include "hyper_parameters.h"
#include "weight_initialization.h"


HyperParameters::HyperParameters(const std::initializer_list<int>& layer_settings, const float& learning_rate_setting) {
    neurons_per_layer = layer_settings;
    learning_rate = learning_rate_setting;
    create_weight_network();
}

std::vector<std::vector<double>> HyperParameters::weight_network() const {
    return weights;
}

void HyperParameters::create_weight_network() {
    int weight_layers = neurons_per_layer.size()-1;
    weights.resize(weight_layers);
    
    for (int i=0; i<weight_layers; i++) {
        weights[i].resize(neurons_per_layer[i] * neurons_per_layer[i+1]);
        std::generate(weights[i].begin(), weights[i].end(), WeightInitialization::weight_generator_simple(neurons_per_layer[i]));
    }
}
