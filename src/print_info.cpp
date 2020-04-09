#include <iostream>
#include <string>

#include "print_info.h"

void PrintInfo::welcome_message() const
{
    std::cout << "Welcome to JaNNI - Just another Neural Network Implementation\n\n";
    std::cout << "JaNNI is a simple neural network that uses the MNIST data set for training and\n";
    std::cout << "testing. Especially the training might run from a few minutes up to several\n";
    std::cout << "hours. The computation time depends on the settings as well as on the system\n";
    std::cout << "you are using.\n"
              << std::endl;
}

int PrintInfo::proceed_confirmation()
{
    std::string answer;

    while (answer != "Y" && answer != "Yes" && answer != "y" && answer != "yes")
    {
        std::cout << "Do you want to continue? [Yes/no] ";
        std::cin >> answer;

        if (answer == "Y" || answer == "Yes" || answer == "y" || answer == "yes")
        {
            std::cout << "Proceeding..." << std::endl;
            std::cout << std::endl;
        }
        else if (answer == "N" || answer == "No" || answer == "n" || answer == "no")
        {
            std::cout << "So sad... Aborting..." << std::endl;
            exit(0);
        }
        else
        {
            std::cout << "A simple question a you failed... So sad..." << std::endl;
        }
    }
}

void PrintInfo::done_message() const
{
    std::cout << "DONE!" << std::endl;
}