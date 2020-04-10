#ifndef RUN_CREATOR_H
#define RUN_CREATOR_H

#include <string>
#include <vector>

#include "mnist_data.h"

class RunCreator
{
public:
    RunCreator(const std::string &,
               const std::string &,
               const std::string &,
               const std::string &,
               const std::initializer_list<int> &,
               const float &);

    void setup_training_data_set(const std::string &, const std::string &);
    void setup_hyper_parameters(const std::initializer_list<int> &, const float &);
    void setup_test_data_set(const std::string &, const std::string &);

private:
};

#endif