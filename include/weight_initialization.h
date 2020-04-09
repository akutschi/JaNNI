#ifndef WEIGHT_INITIALIZATION
#define WEIGHT_INITIALIZATION

#include <cmath>
#include <random>

namespace WeightInitialization
{
// Functor for the generator in std::generate
struct weight_generator_simple
{
    int prev_layer;
    weight_generator_simple(int);
    double operator()();
};

}; // namespace WeightInitialization

#endif
