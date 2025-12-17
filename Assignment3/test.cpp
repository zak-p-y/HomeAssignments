#include <gtest/gtest.h>
#include "Battery.h"
#include "Weapon.h"
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Car.h"

TEST(BatteryTest, SetCharge)
{
    Battery battery;
    battery.set_charge(50);
    EXPECT_EQ(battery.get_charge(), 50);
}
TEST(WeaponTest, GetName)
{
    Weapon weapon;
    EXPECT_EQ(weapon.get_name(), "Gun");
}


TEST(TransformerTest, GetAmmo)
{
    Transformer transformer;
    EXPECT_EQ(transformer.get_ammo(), 1000);
}


TEST(AutobotTest, GetColor)
{
    Weapon weapon("Laser");
    Autobot autobot(2, "Blue", 1, 80, 200, &weapon);
    EXPECT_EQ(autobot.get_color(), "Blue");
}


TEST(DecepticonTest, GetHelmet)
{
    Decepticon decepticon(3, 500);
    decepticon.set_helmet(5);
    EXPECT_EQ(decepticon.get_helmet(), 5);
}

TEST(CarTest, GetSpeed)
{
    Car car(120, "Yellow");

    car.set_speed(180);
    EXPECT_EQ(car.get_speed(), 180);
}
