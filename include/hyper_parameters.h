#ifndef HYPER_PARAMETERS_H
#define HYPER_PARAMETERS_H

#include <vector>


class HyperParameters {
public:
    // Constructor
    // Required number of layer and number of neurons per layer,
    // this includes input and output layer
    // e.g. HyperParameters(768, 90 60 50, 10)
    HyperParameters(const std::initializer_list<int>&, const float&);

    std::vector<std::vector<double>> weight_network() const; // Get whole weight network "matrix"
    void create_weight_network();
    // TODO: Update weights function
    // Overloading required. Parameter either int or std::vector. 
    // Depends on batch size.
    // Required during backpropagation.
    //void update_weight_network();
    
private:
    std::vector<std::vector<double>> weights;
    std::vector<int> neurons_per_layer;
    float learning_rate;
};

// weight network:
// [x] create
// [ ] update
// [x] read


#endif