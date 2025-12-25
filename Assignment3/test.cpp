#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include "Battery.h"
#include "Weapon.h"
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Car.h"

TEST(BatteryTest, Methods)
{
    Battery battery;
    battery.set_charge(50);
    EXPECT_EQ(battery.get_charge(), 50);
}

TEST(WeaponTest, Methods)
{
    Weapon weapon("Blaster");
    EXPECT_EQ(weapon.get_name(), "Blaster");
    weapon.set_name("Saber");
    EXPECT_EQ(weapon.get_name(), "Saber");
}

TEST(AutobotTest, MethodsAndOperators)
{
    Autobot a(2, "Blue", 1, 80, 200, new Weapon("Laser"));
    EXPECT_EQ(a.get_arm(), 2);
    EXPECT_EQ(a.get_color(), "Blue");
    EXPECT_TRUE(a.jump());
    EXPECT_TRUE(a.run());

    std::stringstream ss;
    ss << a;
    EXPECT_FALSE(ss.str().empty());
}

TEST(DecepticonTest, MethodsAndOperators)
{
    Decepticon d(3, 500, 2, 100, 300, new Weapon("Null Ray"));
    EXPECT_EQ(d.get_helmet(), 3);
    EXPECT_EQ(d.get_weight(), 500);
    EXPECT_TRUE(d.jump());
    EXPECT_TRUE(d.run());

    std::stringstream ss;
    ss << d;
    EXPECT_FALSE(ss.str().empty());
}

TEST(CarTest, MethodsAndOperators)
{
    Car c(120, "Yellow", 1, 60, 150, new Weapon("Rocket"));
    EXPECT_EQ(c.get_speed(), 120);
    EXPECT_EQ(c.get_color(), "Yellow");
    EXPECT_TRUE(c.jump());
    EXPECT_TRUE(c.run());

    std::stringstream ss;
    ss << c;
    EXPECT_FALSE(ss.str().empty());
}

TEST(TransformerTest, BaseMethods)
{
    Autobot a(1, "Red", 5, 50, 10, new Weapon("Pistol"));
    EXPECT_EQ(a.get_level(), 5);
    a.level_up();
    EXPECT_EQ(a.get_level(), 6);
    EXPECT_TRUE(a.fire());
    EXPECT_EQ(a.get_ammo(), 9);
}

TEST(PolymorphismTest, ExplicitCalls)
{
    Autobot a;
    Decepticon d;
    Car c;

    EXPECT_NO_THROW(a.printInfo());
    EXPECT_NO_THROW(a.specialAction());
    EXPECT_NO_THROW(d.printInfo());
    EXPECT_NO_THROW(d.specialAction());
    EXPECT_NO_THROW(c.printInfo());
    EXPECT_NO_THROW(c.specialAction());
}

TEST(PolymorphismTest, PointerCalls)
{
    Transformer* ptr = new Autobot(1, "Red", 1, 10, 10, new Weapon("W1"));
    EXPECT_NO_THROW(ptr->printInfo());
    EXPECT_NO_THROW(ptr->specialAction());
    delete ptr;

    ptr = new Decepticon(1, 100, 1, 10, 10, new Weapon("W2"));
    EXPECT_NO_THROW(ptr->printInfo());
    EXPECT_NO_THROW(ptr->specialAction());
    delete ptr;
}

TEST(PolymorphismTest, VectorIteration)
{
    std::vector<Transformer*> robots;
    for (int i = 0; i < 3; ++i)
    {
        robots.push_back(new Autobot(i, "Color", i, 10, 100, new Weapon("W")));
        robots.push_back(new Decepticon(i, 100, i, 10, 100, new Weapon("W")));
        robots.push_back(new Car(i, "Color", i, 10, 100, new Weapon("W")));
    }

    EXPECT_EQ(robots.size(), 9);

    for (auto r : robots)
    {
        EXPECT_NO_THROW(r->printInfo());
        EXPECT_NO_THROW(r->specialAction());
    }

    for (auto r : robots)
    {
        delete r;
    }
}
