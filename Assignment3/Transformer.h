#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "Battery.h"
#include "Weapon.h"

class Transformer {
private:
    int _level;
    Battery battery; 
    Weapon* weapon;   
    int _fuel;
    int _ammo;
    
public:
    Transformer(int lev = 0, int f = 10, int am = 1000, Weapon* wp = nullptr);
    
    
    void set_level(int value);
    void set_battery(int value);
    void set_weapon(const std::string& new_name);
    void set_fuel(int value);
    void set_ammo(int value);
    
    
    int get_level() const;
    int get_battery() const;
    std::string get_weapon() const;
    int get_fuel() const;
    int get_ammo() const;
    
    
    bool fire();
    bool level_up();
    
    
    ~Transformer();
};

#endif
