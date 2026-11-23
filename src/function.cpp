#include "function.h"
#include "vec.h"

Function::Function(double (*f)(const Vec &p), double (*dx)(const Vec &p),
                   double (*dy)(const Vec &p)) {
  this->f = f;
  this->dx = dx;
  this->dy = dy;
}

double Function::evaluate(const Vec &p) { return f(p); }
Vec Function::gradient(const Vec &p) { return Vec{dx(p), dy(p)}; }
