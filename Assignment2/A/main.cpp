/*
* Pavel Zak
* st142062@student.spbu.ru
* Home_assignment number one
*/


#include <iostream>
#include <string>
#include "reverse.h"

int main() {
    std::string file_path;
    std::cout <<"Enter file path:\n";  
    std::getline(std::cin, file_path);
    Reverse(file_path);
    return 0;
}

