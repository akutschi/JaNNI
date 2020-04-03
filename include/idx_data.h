#ifndef IDX_DATA_H
#define IDX_DATA_H

#include <fstream>
#include <vector>


class IDXDataSet {
public:
    IDXDataSet(const std::string&);
    
    std::vector<int> magic_number() const;
    std::vector<int> dimension_values() const;
    std::vector<std::vector<int>> data_bytes() const;
private:
    std::ifstream data_stream;
    void magic_number(const std::string&);
    void dimension_values(const std::string&);
    void data_bytes(const std::string&);
    std::vector<int> magic_number_values{0, 0};
    std::vector<int> data_dim_values;
    std::vector<std::vector<int>> data_set; 
    int big_to_little_endian(char*);
};


#endif