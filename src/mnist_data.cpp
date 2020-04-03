#include "mnist_data.h"


MNISTDataSet::MNISTDataSet(const std::string& data_path, const std::string& label_path)
: mnist_data() {
    mnist_struct(data_path, label_path);
}

MNISTDataEntry MNISTDataSet::mnist_struct(int& row) const {
    return mnist_data[row];
}

void MNISTDataSet::mnist_struct(const std::string& data_path, const std::string& label_path) {
    
    // Get information for data
    IDXDataSet data_object(data_path);
    std::vector<std::vector<int>> data_temp = data_object.data_bytes();

    for (int row=0; row<data_temp.size(); row++) {
        mnist_data.push_back(MNISTDataEntry());
        // Move row vector to mnist struct mnist_data
        // Use move semantics with std::move - very performant
        // See also https://www.modernescpp.com/index.php/copy-versus-move-semantic-a-few-numbers
        mnist_data[row].data = std::move(data_temp[row]);
    }


    // Get information label
    IDXDataSet label_object(label_path);
    std::vector<std::vector<int>> label_temp = label_object.data_bytes();

    for (int row=0; row<data_temp.size(); row++) {
        // Move row vector to mnist struct mnist_data
        // Use move semantics with std::move - very performant
        // See also https://www.modernescpp.com/index.php/copy-versus-move-semantic-a-few-numbers
        mnist_data[row].label = std::move(label_temp[row][0]);
    }
}