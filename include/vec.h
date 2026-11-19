#ifndef VEC_H
#define VEC_H
struct Vec {
  double x = 0.0;
  double y = 0.0;

  Vec(double x, double y);

  double length() const;
  double dot(const Vec &v) const;
};

Vec operator+(const Vec &a, const Vec &b);
Vec operator-(const Vec &a, const Vec &b);
Vec operator*(const Vec &v, const double a);
Vec operator*(const double a, const Vec &v);
void operator+=(Vec &a, const Vec &b);
void operator-=(Vec &a, const Vec &b);
void operator*=(Vec &v, const double a);
double dot(const Vec &a, const Vec &b);
#endif
