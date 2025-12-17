#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"
#include <string>

class Decepticon : public Transformer
{
private:
    int helmet;
    int weight;
public:
    Decepticon(int helm = 0, int w = 0, int lev = 0, int f = 10, int am = 1000, Weapon* wp = nullptr);

    void set_helmet(int value);
    void set_weight(int value);
    int get_helmet() const;
    int get_weight() const;
    bool jump();
    bool run();

    void printInfo() override;
    void specialAction() override;
};

std::ostream& operator<<(std::ostream& os, const Decepticon& d);

#endif
