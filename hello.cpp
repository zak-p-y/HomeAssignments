/*
* Pavel Zak
* st142062@student.spbu.ru
* Home_assignment number one
*/

#include "hello.h"
#include <iostream>

void printHello() {

	std::cout << "Hello, world"<< std::endl;
	while (true) {
		std::string a;
		std::getline(std::cin, a);
		std::cout <<a<< std::endl;

}

}

