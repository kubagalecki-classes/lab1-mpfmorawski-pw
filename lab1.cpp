#include <iostream>
#include <math.h>

class Wektor2D
{
public:
    double x;
    double y;
    double norm() { return sqrt(x * x + y * y); }
    void   print() { std::cout << norm() << '\n'; }
};

int main()
{
    Wektor2D Vector1;
    Vector1.x = 1.12;
    Vector1.y = 2.2;
    Vector1.print();
}