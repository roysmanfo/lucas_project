#include "function.h"
#include "vec.h"

Function::Function(double (*f)(const Vec &p), double (*dx)(const Vec &p),
                   double (*dy)(const Vec &p), double known_min) {
  this->f = f;
  this->dx = dx;
  this->dy = dy;
  this->known_min = known_min;
}

double Function::evaluate(const Vec &p) const { return f(p); }
Vec Function::gradient(const Vec &p) const { return Vec{dx(p), dy(p)}; }

double Function::get_known_min() const { return known_min; }
