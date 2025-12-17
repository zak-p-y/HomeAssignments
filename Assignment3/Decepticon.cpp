#include "Decepticon.h"
#include <iostream>

Decepticon::Decepticon(int helm, int w, int lev, int f, int am, Weapon* wp)
    : Transformer(lev, f, am, wp), helmet(helm), weight(w) {}

void Decepticon::set_helmet(int value)
{
    helmet = value;
}
void Decepticon::set_weight(int value)
{
    weight = value;
}
int Decepticon::get_helmet() const
{
    return helmet;
}
int Decepticon::get_weight() const
{
    return weight;
}
bool Decepticon::jump()
{
    return true;
}
bool Decepticon::run()
{
    return true;
}

void Decepticon::printInfo()
{
    std::cout << "Decepticon::printInfo" << std::endl;
}

void Decepticon::specialAction()
{
    std::cout << "Decepticon::specialAction" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Decepticon& d)
{
    os << static_cast<const Transformer&>(d)
       << ", Helmet: " << d.get_helmet()
       << ", Weight: " << d.get_weight();
    return os;
}
