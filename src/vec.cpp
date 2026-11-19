#include <cmath>
#include "vec.h"

Vec::Vec()
{
    x = 0;
    y = 0;
}

Vec::Vec(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Vec::getX() const { return x; }
double Vec::getY() const { return y; }
double Vec::length() const
{
    return sqrt(x * x + y * y);
}

double Vec::dot(const Vec &v) const
{
    return getX() * v.getX() + getY() * v.getY();
}

Vec operator+(const Vec &a, const Vec &b)
{
    return Vec(a.getX() + b.getX(), a.getY() + b.getY());
}

Vec operator-(const Vec &a, const Vec &b)
{
    return Vec(a.getX() - b.getX(), a.getY() - b.getY());
}

Vec operator*(const Vec &a, const double d)
{
    return Vec(a.getX() * d, a.getY() * d);
}

double dot(const Vec &a, const Vec &b)
{
    return a.dot(b);
}
