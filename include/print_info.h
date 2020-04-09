#ifndef PRINT_INFO_H
#define PRINT_INFO_H

#include <string>

class PrintInfo
{
public:
    void welcome_message() const;
    int proceed_confirmation();
    void done_message() const;
};

#endif