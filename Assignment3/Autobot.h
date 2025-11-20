#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"
#include <string>

class Autobot : public Transformer {
private:
    int arm;
    std::string color;
public:
    Autobot(int a, std::string col, int lev = 0, int f = 10, int am = 1000, Weapon* wp = nullptr);
    
    void set_arm(int value);
    void set_color(const std::string& value);
    
    int get_arm() const;
    std::string get_color() const;
    
    bool jump();
    bool run();
};

#endif
