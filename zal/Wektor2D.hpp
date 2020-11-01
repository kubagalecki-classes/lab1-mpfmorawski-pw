class Wektor2D
{
public:
  Wektor2D(){ x = 0.;  y = 0.; }

  Wektor2D(double vec_x, double vec_y){ x = vec_x; y = vec_y; }

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

