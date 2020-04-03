#include <fstream>
#include <iostream>
#include <functional> // std::multiplies
#include <numeric> // std::accumulate

#include "idx_data.h"


IDXDataSet::IDXDataSet(const std::string& path) 
: data_set() {
    magic_number(path);
    dimension_values(path);
    data_bytes(path);
}

void IDXDataSet::magic_number(const std::string& path) {
    data_stream.open(path, std::ios::in | std::ios::binary);

    char magic_number_raw[4];
        
    data_stream.read(&magic_number_raw[0], 4);
    magic_number_values[0] = magic_number_raw[2]; // Data type
    magic_number_values[1] = magic_number_raw[3]; // Number of dimensions

    data_stream.close();
}

std::vector<int> IDXDataSet::magic_number() const {
    return magic_number_values ;
}

void IDXDataSet::dimension_values(const std::string& path) {
    data_stream.open(path, std::ios::in | std::ios::binary);

    int bytes_to_ignore = 4;
    &data_stream.ignore(bytes_to_ignore);

    for (int i=0; i<magic_number_values[1]; i++) {
        char magic_data_dim_raw[4];
        data_stream.read(&magic_data_dim_raw[0], 4);
        int dim = big_to_little_endian(magic_data_dim_raw);
        IDXDataSet::data_dim_values.push_back(dim);
    }

    data_stream.close();
}

std::vector<int> IDXDataSet::dimension_values() const {
    return data_dim_values;
}

void IDXDataSet::data_bytes(const std::string& path) {
    data_stream.open(path, std::ios::in | std::ios::binary);

    int size = std::accumulate(begin(data_dim_values)+1 , end(data_dim_values), 1, std::multiplies<int>()) ;
    unsigned char pix[size];

    int bytes_to_ignore = 4 + magic_number_values[1] * 4;
    &data_stream.ignore(bytes_to_ignore);

    // Create row 
    for (int row=0; row<data_dim_values[0]; row++) {
        data_set.push_back(std::vector<int>());

        // Create column
        for (int col=0; col<sizeof(pix); col++) { 
            &data_stream.read((char*)&pix[col], 1);
            unsigned int pixel_value = pix[col];
            data_set[row].push_back(pixel_value);
        }
    }

    data_stream.close();
}

std::vector<std::vector<int>> IDXDataSet::data_bytes() const {
    return data_set;
}

int IDXDataSet::big_to_little_endian(char* byte) {
  return ((byte[0] & 0xff) << 24) | ((byte[1] & 0xff) << 16) |
         ((byte[2] & 0xff) <<  8) | ((byte[3] & 0xff) <<  0);
}

