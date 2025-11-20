#ifndef BATTERY_H
#define BATTERY_H


class Battery {
    private:
        int charge;
    public:
        Battery(int chrg=100);
	void set_charge(int value);
	int get_charge() const;
};

#endif
