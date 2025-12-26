#include "Transformer.h"


Transformer::Transformer(int lev, int f, int am, Weapon* wp) 
    : _level(lev), battery(), weapon(wp), _fuel(f), _ammo(am) {}

void Transformer::set_level(int value) {
    _level = value;
}

void Transformer::set_battery(int value) {
    battery.set_charge(value);
}

//void Transformer::set_weapon(const std::string& new_name) {
//    if (weapon != nullptr) {
  //      weapon->set_name(new_name);
 //   }
//}

void Transformer::set_weapon(Weapon* wp) {
    weapon = wp; 
}


void Transformer::set_fuel(int value) {
    _fuel = value;
}

void Transformer::set_ammo(int value) {
    _ammo = value;
}


int Transformer::get_level() const {
    return _level;
}

int Transformer::get_battery() const {
    return battery.get_charge();
}

std::string Transformer::get_weapon() const {
    if (weapon != nullptr) {
        return weapon->get_name();
    }
    return "";
}

int Transformer::get_fuel() const {
    return _fuel;
}

int Transformer::get_ammo() const {
    return _ammo;
}


bool Transformer::fire() {
    if (_ammo > 0) {
        _ammo--;
        return true;
    }
    return false;
}

bool Transformer::level_up() {
    _level++;
    return true;
}


Transformer::~Transformer() {}
