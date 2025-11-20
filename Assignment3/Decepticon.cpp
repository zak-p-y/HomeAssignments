#include "Decepticon.h"

Decepticon::Decepticon(int helm, int w, int lev, int f, int am, Weapon* wp) 
    : helmet(helm), weight(w), Transformer(lev, f, am, wp) {}

void Decepticon::set_helmet(int value) {
    helmet = value;
}

void Decepticon::set_weight(int value) {
    weight = value;
}

int Decepticon::get_helmet() const {
    return helmet;
}

int Decepticon::get_weight() const {
    return weight;
}

bool Decepticon::jump() {
    return true;
}

bool Decepticon::run() {
    return true;
}
