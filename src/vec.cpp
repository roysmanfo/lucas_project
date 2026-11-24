#include "vec.h"
#include <cmath>
#include <ostream>

Vec::Vec(double x, double y){
  this->x = x;
  this->y = y;
}

Vec::Vec(const Vec &v) {
  this->x = v.x;
  this->y = v.y;
}

Vec operator+(const Vec &a, const Vec &b) { return Vec(a.x + b.x, a.y + b.y); }
Vec operator-(const Vec &a, const Vec &b) { return Vec(a.x - b.x, a.y - b.y); }
void operator+=(Vec &a, const Vec &b) {
  a.x += b.x;
  a.y += b.y;
}
void operator-=(Vec &a, const Vec &b) {
  a.x -= b.x;
  a.y -= b.y;
}
Vec operator*(const Vec &v, const double a) { return Vec(v.x * a, v.y * a); }
Vec operator*(const double a, const Vec &v) { return v * a; }
void operator*=(Vec &v, const double a) {
  v.x *= a;
  v.y *= a;
}

double Vec::length() const { return sqrt(x * x + y * y); }
double Vec::dot(const Vec &v) const { return x * v.x + y * v.y; }
double dot(const Vec &a, const Vec &b) { return a.dot(b); }

std::ostream& operator<<(std::ostream& os, const Vec& v)  {
    os << "Vec(" << v.x << ", " << v.y << ")";
    return os;
}
