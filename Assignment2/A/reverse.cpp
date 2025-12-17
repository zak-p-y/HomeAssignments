/*
* Pavel Zak
* st142062@student.spbu.ru
* Home_assignment number one
*/


#include <string> 
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
void Reverse(std::string file_path) {
    std::ifstream infile;
    infile.open(file_path, std::ios::binary | std::ios::in);
    
    int filesize = std::filesystem::file_size(file_path); 
    char* file_array = new char[filesize];
    infile.read(file_array, filesize);
    std::reverse(file_array, file_array + filesize);  
    std::ofstream outfile("outfile.txt", std::ios::binary | std::ios::out);
    outfile.write(file_array, filesize);

    delete[] file_array;
    outfile.close();
    infile.close();
    std::cout << "Data was writted";
}
