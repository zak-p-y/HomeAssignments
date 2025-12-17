#include "Car.h"

Car::Car(int sp, std::string col, int lev, int f, int am, Weapon* wp) 
    : Transformer(lev, f, am, wp), speed(sp), color(col) {}

void Car::set_speed(int value) {
    speed = value;
}

void Car::set_color(const std::string& value) {
    color = value;
}

int Car::get_speed() const {
    return speed;
}

std::string Car::get_color() const {
    return color;
}

bool Car::jump() {
    return true;
}

bool Car::run() {
    return true;
}
