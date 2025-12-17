#include "Autobot.h"

Autobot::Autobot(int a, std::string col, int lev, int f, int am, Weapon* wp) 
    : Transformer(lev, f, am, wp), arm(a), color(col) {}

void Autobot::set_arm(int value) {
    arm = value;
}

void Autobot::set_color(const std::string& value) {
    color = value;
}

int Autobot::get_arm() const {
    return arm;
}

std::string Autobot::get_color() const {
    return color;
}

bool Autobot::jump() {
    return true;
}

bool Autobot::run() {
    return true;
}
