#include "Weapon.h"

Weapon::Weapon(std::string n) : name(n) {}

void Weapon::set_name(std::string value) {
	name = value;
}
std::string Weapon::get_name() const {
	return name;
}
