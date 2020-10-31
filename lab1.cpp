#include <iostream>
#include <math.h>

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

    double x;
    double y;
    double norm() { return sqrt(x * x + y * y); }
    void   print() { std::cout << norm() << '\n'; }
};

int main()
{
    Wektor2D Vector1{1., 1.};
    Wektor2D Vector2{2., 2.};
    Wektor2D Vector3{3., 3.};
    std::cout << "Oznaczone miejsce w kodzie \n";
}

/*
Po wykonaniu otrzymano:
  Wektor o wspolrzednych x = 1 y = 1 został utworzony!
  Wektor o wspolrzednych x = 2 y = 2 został utworzony!
  Wektor o wspolrzednych x = 3 y = 3 został utworzony!
  Oznaczone miejsce w kodzie
  Wektor o wspolrzednych x = 3 y = 3 został usuniety!
  Wektor o wspolrzednych x = 2 y = 2 został usuniety!
  Wektor o wspolrzednych x = 1 y = 1 został usuniety!
  */