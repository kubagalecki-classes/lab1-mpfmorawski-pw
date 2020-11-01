#include <iostream>

class Wektor2D
{
public:
    Wektor2D()
    {
        x = 0.;
        y = 0.;
    }

    Wektor2D(double vec_x, double vec_y)
    {
        x = vec_x;
        y = vec_y;
    }

    void   setX(double vec_x) { x = vec_x; }
    double getX() { return x; };
    void   setY(double vec_y) { y = vec_y; }
    double getY() { return y; }

private:
    double x;
    double y;
};

Wektor2D operator+(Wektor2D Vec1, Wektor2D Vec2)
{
    return Wektor2D{Vec1.getX() + Vec2.getX(), Vec1.getY() + Vec2.getY()};
}

double operator*(Wektor2D Vec1, Wektor2D Vec2)
{
    return ((Vec1.getX() * Vec2.getX()) + (Vec1.getY() * Vec2.getY()));
}

int main()
{
    Wektor2D v1{};         // Konstruktor domyślny, wektor o wsp. [0, 0]
    v1.setX(1.);           // setter
    v1.setY(1.);           // setter
    double x1 = v1.getX(); // getter
    std::cout << "x1 = " << x1 << std::endl;
    double y1 = v1.getY(); // getter
    std::cout << "y1 = " << y1 << std::endl;
    Wektor2D v2{2., 2.}; // Konstruktor nadający współrzędne

    Wektor2D sum = v1 + v2; // dodawanie wektorów
    std::cout << "sum = [" << sum.getX() << ", " << sum.getY() << "] " << std::endl;

    double prod = v1 * v2; // iloczyn skalarny
    std::cout << "prod = " << prod << std::endl;
}
