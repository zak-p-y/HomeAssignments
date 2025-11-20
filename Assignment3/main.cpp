#include <iostream>
#include "Autobot.h"
#include "Decepticon.h"
#include "Car.h"
#include "Weapon.h"

int main() {
	Weapon laser("Laser Gun");
	Weapon plasma("Plasma Gun");
	Weapon rocket("Rocket Gun");
	Autobot optimus(2, "Blue", 1, 80, 200, &laser);
   	 Decepticon megatron(3, 500, 2, 100, 300, &plasma);
   	 Car bumblebee(120, "Yellow", 1, 60, 150, &rocket);

	 optimus.set_arm(5);
	std::cout << "After set_arm(5): " << optimus.get_arm() << std::endl;

	megatron.set_helmet(5);
	std::cout << "After set_helmet(5): " << megatron.get_helmet() << std::endl;


	bumblebee.set_speed(180);
	std::cout << "After set_speed(180): " << bumblebee.get_speed() << std::endl;
	return 0;
}
