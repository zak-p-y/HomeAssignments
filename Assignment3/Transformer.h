#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "Battery.h"
#include "Weapon.h"
#include <string>
#include <iostream>

class Transformer
{
private:
    int _level;
    Battery battery;
    Weapon* weapon;
    int _fuel;
    int _ammo;

public:
    Transformer(int lev = 0, int f = 10, int am = 1000, Weapon* wp = nullptr);
    Transformer(const Transformer& other);
    Transformer(Transformer&& other) noexcept;
    virtual ~Transformer();

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

    virtual void printInfo() = 0;
    virtual void specialAction();

};

std::ostream& operator<<(std::ostream& os, const Transformer& t);

#endif
