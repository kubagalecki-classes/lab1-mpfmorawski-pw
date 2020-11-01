#include <cmath>
#include <iostream>

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

    ~Wektor2D()
    {
        std::cout << "Wektor nr " << num_wek << " o wspolrzednych x = " << x << " y = " << y
                  << " został usuniety!\n";
        --num_wek;
    }

    static Wektor2D kart(double kart_x, double kart_y)
    {
        Wektor2D Vector_kart{kart_x, kart_y};
        return Vector_kart;
    }

    static Wektor2D bieg(double bieg_r, double bieg_fi)
    {
        Wektor2D Vector_bieg{bieg_r * cos(bieg_fi), bieg_r * sin(bieg_fi)};
        return Vector_bieg;
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

    Wektor2D(double vec_x, double vec_y)
    {
        x = vec_x;
        y = vec_y;
        ++num_wek;
        std::cout << "Wektor nr " << num_wek << " o wspolrzednych x = " << x << " y = " << y
                  << " został utworzony! \n";
    }
};

std::ostream& operator<<(std::ostream& os, const Wektor2D& Vector)
{
    os << "[" << Vector.x << ", " << Vector.y << "] ";
    return os;
}

int Wektor2D::num_wek = 0;

int main()
{
    Wektor2D Vector1 = Wektor2D::kart(1., 1.);
    Wektor2D Vector2 = Wektor2D::bieg(1., 1.);
}

/*
Po wykonaniu otrzymano:
  Wektor nr 1 o wspolrzednych x = 1 y = 1 został utworzony!
  Wektor nr 2 o wspolrzednych x = 0.540302 y = 0.841471 został utworzony!
  Wektor nr 2 o wspolrzednych x = 0.540302 y = 0.841471 został usuniety!
  Wektor nr 1 o wspolrzednych x = 1 y = 1 został usuniety!
*/