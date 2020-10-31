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

    Informer informer;

    double x;
    double y;
    double norm() { return sqrt(x * x + y * y); }
    void   print() { std::cout << norm() << "\n"; }
};

int main()
{
    Wektor2D Vector1{1., 1.};
    Wektor2D Vector2{2., 2.};
    std::cout << "Oznaczone miejsce w kodzie \n";
}

/*
Po wykonaniu otrzymano:
  Konstruktor Informera
  Wektor o wspolrzednych x = 1 y = 1 został utworzony!
  Konstruktor Informera
  Wektor o wspolrzednych x = 2 y = 2 został utworzony!
  Oznaczone miejsce w kodzie
  Wektor o wspolrzednych x = 2 y = 2 został usuniety!
  Destruktor Informera
  Wektor o wspolrzednych x = 1 y = 1 został usuniety!
  Destruktor Informer
*/