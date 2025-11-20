#ifndef CAR_H
#define CAR_H

#include "Transformer.h"
#include <string>

class Car : public Transformer {
private:
    int speed;
    std::string color;
public:
    Car(int sp, std::string col, int lev = 0, int f = 10, int am = 1000, Weapon* wp = nullptr);
    
    void set_speed(int value);
    void set_color(const std::string& value);
    
    int get_speed() const;
    std::string get_color() const;
    
    bool jump();
    bool run();
};

#endif
