#ifndef VEC_H
#define VEC_H

#include <ostream>

/*
 * Rappresenta un punto o un vettore (x,y) in coordinate cartesiane
 */
struct Vec {
  double x = 0.0;
  double y = 0.0;

  Vec(double x, double y);
  Vec(const Vec &v);

  /* Restituisce la norma del vettore (x,y) */
  double length() const;

  /* Restituisce il prodotto scalare con un altro vettore */
  double dot(const Vec &v) const;
};

Vec operator+(const Vec &a, const Vec &b);
Vec operator-(const Vec &a, const Vec &b);
Vec operator*(const Vec &v, const double a);
Vec operator*(const double a, const Vec &v);
void operator+=(Vec &a, const Vec &b);
void operator-=(Vec &a, const Vec &b);
void operator*=(Vec &v, const double a);

/* Restituisce il prodotto scalare tra due vettori */
double dot(const Vec &a, const Vec &b);

std::ostream &operator<<(std::ostream &os, const Vec &p);

#endif
