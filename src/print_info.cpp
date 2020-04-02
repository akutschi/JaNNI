#include <iostream>
#include <string>

#include "print_info.h"


void PrintInfo::welcome_message() const {
    std::cout << "Welcome to JaNNI - Just another Neural Network Implementation\n" << std::endl;
}

void PrintInfo::done_message() const {
    std::cout << "DONE!" << std::endl;
}