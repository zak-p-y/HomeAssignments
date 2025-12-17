#ifndef WEAPON_H
#define WEAPON_H
#include <string>
class Weapon
{
private:
    std::string name;
public:
    Weapon(std::string n="Gun");
    void set_name(std::string value);
    std::string get_name() const;
};


#endif
