#include <iostream>
#include <vector>
#include "Autobot.h"
#include "Decepticon.h"
#include "Car.h"
#include "Weapon.h"

int main()
{
    Autobot a(2, "Blue", 1, 80, 200, new Weapon("Laser Gun"));
    a.printInfo();
    a.specialAction();
    std::cout << a << std::endl;

    Decepticon d(3, 500, 2, 100, 300, new Weapon("Plasma Gun"));
    d.printInfo();
    d.specialAction();
    std::cout << d << std::endl;

    Car c(120, "Yellow", 1, 60, 150, new Weapon("Rocket Gun"));
    c.printInfo();
    c.specialAction();
    std::cout << c << std::endl;

    Transformer* ptr = &a;
    ptr->printInfo();
    ptr = &d;
    ptr->printInfo();
    ptr = &c;
    ptr->printInfo();

    std::vector<Transformer*> robots;
    robots.push_back(new Autobot(1, "Red", 0, 10, 1000, new Weapon("Blaster")));
    robots.push_back(new Autobot(2, "Green", 0, 10, 1000, new Weapon("Blaster")));
    robots.push_back(new Autobot(3, "Blue", 0, 10, 1000, new Weapon("Blaster")));
    robots.push_back(new Decepticon(1, 100, 0, 10, 1000, new Weapon("Null Ray")));
    robots.push_back(new Decepticon(2, 200, 0, 10, 1000, new Weapon("Null Ray")));
    robots.push_back(new Decepticon(3, 300, 0, 10, 1000, new Weapon("Null Ray")));
    robots.push_back(new Car(50, "Black", 0, 10, 1000, new Weapon("Bumper")));
    robots.push_back(new Car(60, "White", 0, 10, 1000, new Weapon("Bumper")));
    robots.push_back(new Car(70, "Gray", 0, 10, 1000, new Weapon("Bumper")));

    for (auto r : robots)
    {
        r->printInfo();
    }

    for (auto r : robots)
    {
        delete r;
    }

    return 0;
}
