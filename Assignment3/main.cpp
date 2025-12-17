#include <iostream>
#include <vector>
#include "Autobot.h"
#include "Decepticon.h"
#include "Car.h"
#include "Weapon.h"

int main()
{
    Weapon laser("Laser Gun");
    Weapon plasma("Plasma Gun");
    Weapon rocket("Rocket Gun");

    Autobot a(2, "Blue", 1, 80, 200, &laser);
    a.printInfo();
    a.specialAction();
    std::cout << a << std::endl;

    Decepticon d(3, 500, 2, 100, 300, &plasma);
    d.printInfo();
    d.specialAction();
    std::cout << d << std::endl;

    Car c(120, "Yellow", 1, 60, 150, &rocket);
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
    robots.push_back(new Autobot(1, "Red"));
    robots.push_back(new Autobot(2, "Green"));
    robots.push_back(new Autobot(3, "Blue"));
    robots.push_back(new Decepticon(1, 100));
    robots.push_back(new Decepticon(2, 200));
    robots.push_back(new Decepticon(3, 300));
    robots.push_back(new Car(50, "Black"));
    robots.push_back(new Car(60, "White"));
    robots.push_back(new Car(70, "Gray"));

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
