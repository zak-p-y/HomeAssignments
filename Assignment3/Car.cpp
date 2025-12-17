#include "Car.h"
#include <iostream>

Car::Car(int sp, std::string col, int lev, int f, int am, Weapon* wp)
    : Transformer(lev, f, am, wp), speed(sp), color(col) {}

void Car::set_speed(int value)
{
    speed = value;
}
void Car::set_color(const std::string& value)
{
    color = value;
}
int Car::get_speed() const
{
    return speed;
}
std::string Car::get_color() const
{
    return color;
}
bool Car::jump()
{
    return true;
}
bool Car::run()
{
    return true;
}

void Car::printInfo()
{
    std::cout << "Car::printInfo" << std::endl;
}

void Car::specialAction()
{
    std::cout << "Car::specialAction" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Car& c)
{
    os << static_cast<const Transformer&>(c)
       << ", Speed: " << c.get_speed()
       << ", Color: " << c.get_color();
    return os;
}
