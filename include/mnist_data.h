#ifndef MNIST_DATA_H
#define MNIST_DATA_H

#include <vector>
#include <string>

#include "idx_data.h"


struct MNISTDataEntry {
    std::vector<int> data;          // Store pixel color values of the image
    std::vector<int> output;        // Store the output in a 10 column vector
    int label;                      // Store the handwritten digit in number form
    // Constructor using initializer list to initialize its member variables
    MNISTDataEntry() : data(std::vector<int>()), output(std::vector<int>(10)), label(0) {}
};

class MNISTDataSet {
public:
    MNISTDataSet(const std::string&, const std::string&);

    std::vector<MNISTDataEntry> mnist_struct() const;
    MNISTDataEntry mnist_struct(int&) const;                    // Getter to receive a struct from mnist_data
    std::vector<int> data_magic_values() const;
    std::vector<int> data_dimension_values() const;
    std::vector<int> label_magic_values() const;
    std::vector<int> label_dimension_values() const;

private:  
    std::vector<MNISTDataEntry> mnist_data;                     // Vector of structs, holds all MNIST data
    void mnist_struct(const std::string&, const std::string&);  // Setter to fill up the vector of structs
    std::vector<int> data_magic_number;
    std::vector<int> data_magic_dimensions;
    std::vector<int> label_magic_number;
    std::vector<int> label_magic_dimensions;
    
};


#endif