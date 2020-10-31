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
    Wektor2D Vector1{1., 2.};
    Wektor2D Vector2{3., 4.};
    Wektor2D Vector3{};

    std::cout << "Oznaczone miejsce w kodzie 1\n";
    Vector3 = Vector1 + Vector2;
    std::cout << "Oznaczone miejsce w kodzie 2 \n";

    std::cout << "[" << Vector1.getX() << ", " << Vector1.getY() << "] + ";
    std::cout << "[" << Vector2.getX() << ", " << Vector2.getY() << "] = ";
    std::cout << "[" << Vector3.getX() << ", " << Vector3.getY() << "] \n";

    std::cout << "Oznaczone miejsce w kodzie 3\n";
    double iloczSkalar = Vector1 * Vector2;
    std::cout << "Oznaczone miejsce w kodzie 4 \n";

    std::cout << "[" << Vector1.getX() << ", " << Vector1.getY() << "] * ";
    std::cout << "[" << Vector2.getX() << ", " << Vector2.getY() << "] = ";
    std::cout << iloczSkalar << " \n";
}

/*
Po wykonaniu otrzymano:
  Wektor o wspolrzednych x = 1 y = 2 został utworzony! 
  Wektor o wspolrzednych x = 3 y = 4 został utworzony! 
  Utworzenie pustego wektora! 
  Oznaczone miejsce w kodzie 1
  Wektor o wspolrzednych x = 4 y = 6 został utworzony! 
  Wektor o wspolrzednych x = 4 y = 6 został usuniety! 
  Wektor o wspolrzednych x = 1 y = 2 został usuniety! 
  Wektor o wspolrzednych x = 3 y = 4 został usuniety! 
  Oznaczone miejsce w kodzie 2 
  [1, 2] + [3, 4] = [4, 6] 
  Oznaczone miejsce w kodzie 3
  Wektor o wspolrzednych x = 1 y = 2 został usuniety! 
  Wektor o wspolrzednych x = 3 y = 4 został usuniety! 
  Oznaczone miejsce w kodzie 4 
  [1, 2] * [3, 4] = 11 
  Wektor o wspolrzednych x = 4 y = 6 został usuniety! 
  Wektor o wspolrzednych x = 3 y = 4 został usuniety! 
  Wektor o wspolrzednych x = 1 y = 2 został usuniety! 
*/