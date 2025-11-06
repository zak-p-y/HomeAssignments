#include <iostream>
#include <string>
#include <sstream>


int main() {
    std::string a;
    std::getline(std::cin, a);
    std::istringstream iss(a); 
    std::string symbol;
    float* array = new float[100]; 
   int pointer = -1; // point at last. First value is -1 because after adding a number pointer increases

   
   while  (iss>>symbol) {
    std::cout <<array[pointer] << " " << symbol << std::endl;
    if (symbol=="+") {    
        float a = array[pointer - 1] + array[pointer]; 
        array[pointer] = 0;  // set 0 
        pointer -= 1;  
        array[pointer] = a;   //write to previous cell sum 
        
}
    else if (symbol=="-") {
        float a = array[pointer - 1] - array[pointer]; 
        array[pointer] = 0;  // set 0 
        pointer -= 1;  
        array[pointer] = a;   
    }
    else if (symbol=="*") {
        float a = array[pointer -1] * array[pointer]; 
        array[pointer] = 0;  // set 0 
        pointer -= 1;  
        array[pointer] = a;   
    }
    else if (symbol=="/") {
        float a = array[pointer - 1] /  array[pointer]; 
        array[pointer] = 0;  // set 0 
        pointer -= 1;  
        array[pointer] = a;   
    }

    
    else {
    ++pointer;
    float num = std::stof(symbol);  //convert str to float
    
    array[pointer] = num;
    }


}
    std::cout << array[pointer] << std::endl;
    delete[] array;
    
    return 0; 
}
 



