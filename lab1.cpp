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
    Wektor2D()
    {
        ++num_wek;
        std::cout << "Wektor nr " << num_wek << " został utworzony! \n";
    }
    Wektor2D(double vec_x, double vec_y)
    {
        x = vec_x;
        y = vec_y;
        ++num_wek;
        std::cout << "Wektor nr " << num_wek << " o wspolrzednych x = " << x << " y = " << y
                  << " został utworzony! \n";
    }

    ~Wektor2D()
    {
        std::cout << "Wektor nr " << num_wek << " o wspolrzednych x = " << x << " y = " << y
                  << " został usuniety!\n";
        --num_wek;
    }

    double norm() { return sqrt(x * x + y * y); }
    void   print() { std::cout << norm() << "\n"; }

    void   setX(double vec_x) { x = vec_x; }
    double getX() { return x; };
    void   setY(double vec_y) { y = vec_y; }
    double getY() { return y; }

private:
    static int num_wek;

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

int Wektor2D::num_wek = 0;

int main()
{

    Wektor2D Vector1{1., 1.};
    Wektor2D Vector2{2., 2.};
    Wektor2D Vector3{};
    {
        Wektor2D Vector4{4., 4.};
        Wektor2D Vector5{};
    }
    Wektor2D Vector6{6., 6.};
}

/*
Po wykonaniu otrzymano:
  Wektor nr 1 o wspolrzednych x = 1 y = 1 został utworzony!
  Wektor nr 2 o wspolrzednych x = 2 y = 2 został utworzony!
  Wektor nr 3 został utworzony!
  Wektor nr 4 o wspolrzednych x = 4 y = 4 został utworzony!
  Wektor nr 5 został utworzony!
  Wektor nr 5 o wspolrzednych x = 6.91837e-310 y = 0 został usuniety!
  Wektor nr 4 o wspolrzednych x = 4 y = 4 został usuniety!
  Wektor nr 4 o wspolrzednych x = 6 y = 6 został utworzony!
  Wektor nr 4 o wspolrzednych x = 6 y = 6 został usuniety!
  Wektor nr 3 o wspolrzednych x = 6.95285e-310 y = 4.67546e-310 został usuniety!
  Wektor nr 2 o wspolrzednych x = 2 y = 2 został usuniety!
  Wektor nr 1 o wspolrzednych x = 1 y = 1 został usuniety!
*/