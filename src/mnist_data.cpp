#include "mnist_data.h"

MNISTDataSet::MNISTDataSet(const std::string &data_path, const std::string &label_path)
    : _mnist_data()
{
    mnist_struct(data_path, label_path);
}

std::vector<MNISTDataEntry> MNISTDataSet::mnist_data() const
{
    return _mnist_data;
}

MNISTDataEntry MNISTDataSet::mnist_data(int &row) const
{
    return _mnist_data[row];
}

void MNISTDataSet::mnist_struct(const std::string &data_path, const std::string &label_path)
{
    // Get information for data
    IDXDataSet data_object(data_path);
    std::vector<std::vector<int>> data_temp = data_object.data_bytes();
    _data_magic_number = std::move(data_object.magic_number());
    _data_magic_dimensions = std::move(data_object.dimension_values());

    for (int row = 0; row < _data_magic_dimensions[0]; row++)
    {
        _mnist_data.push_back(MNISTDataEntry());
        // Move row vector to mnist struct mnist_data
        // See also https://www.modernescpp.com/index.php/copy-versus-move-semantic-a-few-numbers
        _mnist_data[row].data = std::move(data_temp[row]);
    }

    // Get information for label
    IDXDataSet label_object(label_path);
    std::vector<std::vector<int>> label_temp = label_object.data_bytes();
    _label_magic_number = std::move(label_object.magic_number());
    _label_magic_dimensions = std::move(label_object.dimension_values());

    for (int row = 0; row < _data_magic_dimensions[0]; row++)
    {
        _mnist_data[row].label = std::move(label_temp[row][0]);
    }
}

std::vector<int> MNISTDataSet::data_magic_values() const
{
    return _data_magic_number;
}

std::vector<int> MNISTDataSet::data_dimension_values() const
{
    return _data_magic_dimensions;
}

std::vector<int> MNISTDataSet::label_magic_values() const
{
    return _label_magic_number;
}

std::vector<int> MNISTDataSet::label_dimension_values() const
{
    return _label_magic_dimensions;
}