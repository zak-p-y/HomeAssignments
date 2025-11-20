#include "Battery.h"

Battery::Battery(int chrg) : charge(chrg) {}

void Battery::set_charge(int value) {
	charge = value;
}

int Battery::get_charge () const {
            return charge;
}


