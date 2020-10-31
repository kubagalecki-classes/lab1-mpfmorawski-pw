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

    double norm() { return sqrt(x * x + y * y); }
    void   print() { std::cout << norm() << "\n"; }

    void setX(double vec_x) { x = vec_x; }
    int  getX() { return x; };
    void setY(double vec_y) { y = vec_y; }
    int  getY() { return y; }

private:
    double x;
    double y;
};

int main()
{
    Wektor2D Vector1{1., 1.};
    // std::cout << "Vector1.x = " << Vector1.x << "  Vector1.y = " << Vector1.y << " \n";
    std::cout << "Vector1.getX() = " << Vector1.getX() << " Vector1.getY() = " << Vector1.getY()
              << " \n";

    Vector1.setX(2.);
    std::cout << "Vector1.setX(2.); ";
    Vector1.setY(2.);
    std::cout << "Vector1.setY(2.); \n";

    // std::cout << "Vector1.x = " << Vector1.x << "  Vector1.y = " << Vector1.y << " \n";
    std::cout << "Vector1.getX() = " << Vector1.getX() << " Vector1.getY() = " << Vector1.getY()
              << " \n";

    std::cout << "Oznaczone miejsce w kodzie \n";
}

/*
Po wykonaniu kodu z odkomentowanymi linijkami zawierającymi Vector1.x oraz Vector1.y nie udało się
skompilować.

Po wykonaniu kodu otrzymano:
  Wektor o wspolrzednych x = 1 y = 1 został utworzony! 
  Vector1.getX() = 1 Vector1.getY() = 1 
  Vector1.setX(2.); Vector1.setY(2.); 
  Vector1.getX() = 2 Vector1.getY() = 2 
  Oznaczone miejsce w kodzie 
  Wektor o wspolrzednych x = 2 y = 2 został usuniety! 
*/