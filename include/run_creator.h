#ifndef RUN_CREATOR_H
#define RUN_CREATOR_H

#include <string>
#include <vector>

#include "mnist_data.h"
#include "hyper_parameters.h"

class RunCreator
{
public:
    RunCreator(const std::string &,
               const std::string &,
               const std::string &,
               const std::string &,
               const std::initializer_list<int> &,
               const float &);

    void forward_propagation();
    void calculate_loss();
    void back_propagation();
    void update_weights();

protected:
    MNISTDataSet _mnist_training_data;
    MNISTDataSet _mnist_test_data;
    HyperParameters _hyper_parameters;
};

#endif

