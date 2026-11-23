#include "function.h"
#include "vec.h"
#include <iostream>

double f1(const Vec &v) { return (v.x * v.x + v.y * v.y) / 2.0; }

double dx1(const Vec &v) { return v.x; }

double dy1(const Vec &v) { return v.y; }

int main(int argc, char const *argv[]) {
  /*

    double x = 4; // p0
    double y = 4; // p0

    Vec p(x, y);

    double a = 1.0 / 5.0;
    const double T = 0.1;
    const double N = 100;

    Vec grad(dx1(x, y), dy1(x, y));

    for (int i = 0; (i < N) && (grad.length() >= T); i++) {
      x -= a * dx1(x, y);
      y -= a * dy1(x, y);
      Vec grad(dx1(x, y), dy1(x, y));
    }
    std::cout << "x = " << x << "  ";
    std::cout << "y = " << y << "  ";
    std::cout << "f(x,y) = " << f1(x, y) << std::endl;
  */

  Vec p(4, 4);

  Function f(f1, dx1, dy1);

  double a = 1.0 / 5.0;
  const double T = 0.1;
  const double N = 100;

  Vec grad = f.gradient(p);
  for (int i = 0; (i < N) && (grad.length() >= T); i++) {
    p -= a * grad;
    grad = f.gradient(p);
  }

  std::cout << "grad: " << grad << std::endl;

  return 0;
}
