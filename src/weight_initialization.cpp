#include <algorithm>
#include <cmath>
#include <random>

#include "weight_initialization.h"


WeightInitialization::weight_generator_simple::weight_generator_simple(int prev_layer) 
:   prev_layer_(prev_layer) { }
    
double WeightInitialization::weight_generator_simple::operator()() {
    double limit = 1.0 / std::sqrt(prev_layer_);

    std::random_device randdev{};
    std::mt19937 generate{randdev()};

    std::uniform_real_distribution<double> dist(-limit,+limit);

    double rand_value = dist(generate);

    return rand_value;
}