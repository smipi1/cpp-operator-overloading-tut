#include <iostream>

template<int M, int L, int T>
class Dimension {
public:
    double _value;

    Dimension(double value)
    : _value { value }
    {}

    void print() {
        std::cout << _value << " "
            << "kg^" << M << " • "
            << "m^" << L << " • "
            << "s^" << T
            << std::endl;
    }
};

// Dimension addition
template <int M, int L, int T>
Dimension<M, L, T> operator+(const Dimension<M, L, T>& lhs, const Dimension<M, L, T>& rhs)
{
    return Dimension<M, L, T>(lhs._value + rhs._value);
}

// Dimension subtraction
template <int M, int L, int T>
Dimension<M, L, T> operator-(const Dimension<M, L, T>& lhs, const Dimension<M, L, T>& rhs)
{
    return Dimension<M, L, T>(lhs._value - rhs._value);
}

// Dimension multiplication
template <int M1, int L1, int T1, int M2, int L2, int T2>
Dimension<M1+M2, L1+L2, T1+T2> operator*(const Dimension<M1, L1, T1>& lhs, const Dimension<M2, L2, T2>& rhs)
{
    return Dimension<M1+M2, L1+L2, T1+T2>(lhs._value * rhs._value);
}

// Dimension division
template <int M1, int L1, int T1, int M2, int L2, int T2>
Dimension<M1-M2, L1-L2, T1-T2> operator/(const Dimension<M1, L1, T1>& lhs, const Dimension<M2, L2, T2>& rhs)
{
    return Dimension<M1-M2, L1-L2, T1-T2>(lhs._value / rhs._value);
}

typedef Dimension<1,0,0> Kilograms;
typedef Dimension<0,1,0> Meters;
typedef Dimension<0,0,1> Seconds;
typedef Dimension<0,1,-1> MetersPerSecond;

int main(int argc, char const *argv[])
{
    Kilograms mass(10.0f);
    Meters length(15.0f);
    Seconds time(15.0f);

    std::cout << "Mass: ";
    mass.print();

    std::cout << "Length: ";
    length.print();

    std::cout << "Time: ";
    time.print();

    auto momentum = mass * length / time;

    std::cout << "Momentum: ";
    momentum.print();

    MetersPerSecond velocity = length / time;

    std::cout << "Velocity: ";
    velocity.print();

    // MetersPerSecond acceleration = length / ( time * time);

    std::cout << std::endl;
    return 0;
}
