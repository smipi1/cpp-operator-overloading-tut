#include <iostream>

class Battery {
    private:
        double _energy;

    public:
        Battery():
            _energy{ 0.0f }
        {}

        void charge(double power_in_watts, double time_in_seconds) {
            _energy += power_in_watts * time_in_seconds;
        }

        void charge(double energy_in_joules) {
            _energy += energy_in_joules;
        }

        void drain(double power_in_watts, double time_in_seconds) {
            _energy -= power_in_watts * time_in_seconds;
        }

        void drain(double energy_in_joules) {
            _energy -= energy_in_joules;
        }

        void drain(double power_in_watts, int time_in_hours) {
            _energy -= power_in_watts * 3600.0f * time_in_hours;
        }

        void reportCharge() {
            std::cout << __PRETTY_FUNCTION__ << ": " << "energy = " << _energy << " J" << std::endl;
        }
};

int main(int argc, char const *argv[])
{
    Battery b;

    b.reportCharge();
    b.charge(10, 15);
    b.reportCharge();
    b.charge(100);
    b.reportCharge();
    b.drain(100);
    b.reportCharge();
    b.drain(10, 15);
    b.reportCharge();

    std::cout << std::endl;
    return 0;
}
