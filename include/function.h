#ifndef FUNCTION_H
#define FUNCTION_H
#include "vec.h"

class Function {
public:
  Function(double (*f)(const Vec &p), double (*dx)(const Vec &p),
           double (*dy)(const Vec &p));
  double evaluate(const Vec &p);
  Vec gradient(const Vec &p);

private:
  double (*f)(const Vec &p);
  double (*dx)(const Vec &p);
  double (*dy)(const Vec &p);
};

#endif
