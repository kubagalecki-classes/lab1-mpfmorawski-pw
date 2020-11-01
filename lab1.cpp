#include <iostream>
#include <math.h>

class Informer
{
public:
    Informer() { std::cout << "Konstruktor Informera \n"; }
    ~Informer() { std::cout << "Destruktor Informera \n"; }
};

class Wektor2D
{
public:
    Wektor2D() { std::cout << "Utworzenie pustego wektora! \n"; }
    Wektor2D(double vec_x, double vec_y)
    {
        x = vec_x;
        y = vec_y;
        std::cout << "Wektor o wspolrzednych x = " << x << " y = " << y << " został utworzony! \n";
    }

    ~Wektor2D()
    {
        std::cout << "Wektor o wspolrzednych x = " << x << " y = " << y << " został usuniety! \n";
    }

    double norm() { return sqrt(x * x + y * y); }
    void   print() { std::cout << norm() << "\n"; }

    void   setX(double vec_x) { x = vec_x; }
    double getX() { return x; };
    void   setY(double vec_y) { y = vec_y; }
    double getY() { return y; }

private:
    double x;
    double y;

    friend std::ostream& operator<<(std::ostream& os, const Wektor2D& Vector);
};

Wektor2D operator+(Wektor2D Vec1, Wektor2D Vec2)
{
    return Wektor2D{Vec1.getX() + Vec2.getX(), Vec1.getY() + Vec2.getY()};
}

double operator*(Wektor2D Vec1, Wektor2D Vec2)
{
    return ((Vec1.getX() * Vec2.getX()) + (Vec1.getY() * Vec2.getY()));
}

std::ostream& operator<<(std::ostream& os, const Wektor2D& Vector)
{
    os << "[" << Vector.x << ", " << Vector.y << "] ";
    return os;
}

int main()
{
    Wektor2D Vector1{1., 2.};
    Wektor2D Vector2{3., 4.};
    std::cout << "Oznaczone miejsce w kodzie \n";
    std::cout << Vector1 << Vector2 << "\n";
}

/*
Po wykonaniu otrzymano:
  Wektor o wspolrzednych x = 1 y = 2 został utworzony! 
  Wektor o wspolrzednych x = 3 y = 4 został utworzony! 
  Oznaczone miejsce w kodzie 
  [1, 2] [3, 4] 
  Wektor o wspolrzednych x = 3 y = 4 został usuniety! 
  Wektor o wspolrzednych x = 1 y = 2 został usuniety! 
*/