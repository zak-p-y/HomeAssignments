#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"

class Decepticon : public Transformer {
private:
    int helmet;
    int weight;
public:
    Decepticon(int helm, int w, int lev = 0, int f = 10, int am = 1000, Weapon* wp = nullptr);
    
    void set_helmet(int value);
    void set_weight(int value);
    
    int get_helmet() const;
    int get_weight() const;
    
    bool jump();
    bool run();
};

#endif
