#include "function.h"
#include "vec.h"
#include "gradient.h"
#include <iostream>

// double f1(const Vec &v) { return (v.x * v.x + v.y * v.y) / 2.0; }
// double dx1(const Vec &v) { return v.x; }
// double dy1(const Vec &v) { return v.y; }

const double T = 0.1;
const int N = 100;


void compute_f_min(
  Function f,
  const Vec &initial_point,
  double known_min,
  double a,
  double T,
  double N
) {

  Vec p(initial_point.x, initial_point.y);

  Vec grad = f.gradient(p);
  for (int i = 0; (i < N) && (grad.length() >= T); i++) {
    p -= a * grad;
    grad = f.gradient(p);
  }

  std::cout << "x=" << p.x
            << "\ty=" << p.y
            << "\tf(x,y)=" << f.evaluate(p)
            << "\terror=" << error(f.evaluate(p), known_min)
            << "\tgrad_norm=" << grad.length()
            << std::endl;
}


int main(int argc, char const *argv[]) {
  std::cout << "f1: " ;
  compute_f_min(
    Function(f1, dx1, dy1),
    Vec(4, 4),
    0,
    1.0/5.0,
    1,
    100
  );

  std::cout << "f2: " ;
  compute_f_min(
    Function(f2, dx2, dy2),
    Vec(1, 1),
    0,
    1.0/5.0,
    1,
    100
  );



  std::cout << "f3: " ;
  compute_f_min(
    Function(f3, dx3, dy3),
    Vec(1, 1),
    0,
    1.0/5.0,
    1,
    100
  );

  return 0;
}
