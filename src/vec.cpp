#include "vec.h"
#include <cmath>

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
