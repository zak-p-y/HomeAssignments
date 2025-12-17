#include "Transformer.h"
#include <iostream>

Transformer::Transformer(int lev, int f, int am, Weapon* wp)
    : _level(lev), battery(), weapon(wp), _fuel(f), _ammo(am) {}

Transformer::Transformer(const Transformer& other)
    : _level(other._level), battery(other.battery), weapon(other.weapon ? new Weapon(*other.weapon) : nullptr),
      _fuel(other._fuel), _ammo(other._ammo) {}

Transformer::Transformer(Transformer&& other) noexcept
    : _level(other._level), battery(std::move(other.battery)), weapon(other.weapon),
      _fuel(other._fuel), _ammo(other._ammo)
{
    other.weapon = nullptr;
}


// В Transformer.cpp

void Transformer::set_level(int value) {
    _level = value;
}

void Transformer::set_battery(int value) {
    battery.set_charge(value);
}

void Transformer::set_weapon(const std::string& new_name) {
    if (weapon != nullptr) {
        weapon->set_name(new_name);
    }
}

void Transformer::set_fuel(int value) {
    _fuel = value;
}

void Transformer::set_ammo(int value) {
    _ammo = value;
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

int Transformer::get_level() const
{
    return _level;
}

int Transformer::get_fuel() const
{
    return _fuel;
}

int Transformer::get_ammo() const
{
    return _ammo;
}

Transformer::~Transformer()
{
//    delete weapon;
}

std::ostream& operator<<(std::ostream& os, const Transformer& t)
{
    os << "Level: " << t.get_level()
       << ", Fuel: " << t.get_fuel()
       << ", Ammo: " << t.get_ammo();
    return os;
}

void Transformer::specialAction()
{
    std::cout << "Transformer::specialAction" << std::endl;
}
