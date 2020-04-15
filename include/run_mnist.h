#ifndef RUN_MNIST_H
#define RUN_MNIST_H

#include "run_creator.h"
#include "hyper_parameters.h"

class RunMNIST : public RunCreator
{
public:
    RunMNIST(const std::string &,
             const std::string &,
             const std::string &,
             const std::string &,
             const std::initializer_list<int> &,
             const int &,
             const int &,
             const float &);

    void forward_propagation();
    void calculate_loss();
    void back_propagation();
};

#endif