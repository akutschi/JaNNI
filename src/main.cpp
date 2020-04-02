#include <iostream>

#include "print_info.h"


int main() {
    PrintInfo output_messages;
    
    output_messages.welcome_message();
    output_messages.done_message();

    return 0;
}