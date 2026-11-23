#include "gradient.h"
#include "vec.h"
#include <cmath>

double f1(const Vec &v) { return (v.x * v.x + v.y * v.y) / 2.0; }
double dx1(const Vec &v) { return v.x; }
double dy1(const Vec &v) { return v.y; }

double f2(const Vec &v) { return (v.x * v.x + 16*v.y * v.y) / 2.0; }
double dx2(const Vec &v) { return v.x; }
double dy2(const Vec &v) { return 16*v.y; }

double f3(const Vec &v) { return pow((v.x * v.x -1),2) + v.y*v.y; }
double dx3(const Vec &v) { return 2*2*v.x*(v.x*v.x-1); }
double dy3(const Vec &v) { return 2*v.y; }

double f4(const Vec &v) { return pow((v.x * v.x -1),2) + v.y*v.y + std::pow((v.x-1),2)/5; }
double dx4(const Vec &v) { return (2*2*v.x*(v.x*v.x-1)) + (2.0/5.0)*(v.x-1); }
double dy4(const Vec &v) { return 2*v.y; }

double f5(const Vec &v) { return 4*std::pow(std::sinh(v.x/2.0),2) + std::pow(v.y,2); }
double dx5(const Vec &v) { return 4*std::sinh(v.x/2.0)*std::cosh(v.x/2.0); }
double dy5(const Vec &v) { return 2*v.y; }

double f6(const Vec &v) { return std::log(1 + v.x*v.x + v.y*v.y); }
double dx6(const Vec &v) { return (2*v.x)/((1 + v.x*v.x + v.y*v.y)); }
double dy6(const Vec &v) { return (2*v.y)/((1+v.x*v.x+v.y*v.y)); }

double f7(const Vec &v) { return 1 - std::exp(-(v.x*v.x+v.y*v.y)); }
double dx7(const Vec &v) { return -std::exp(-(v.x*v.x+v.y*v.y))*(-2*v.x); }
double dy7(const Vec &v) { return -std::exp(-(v.x*v.x+v.y*v.y))*(-2*v.y); }

double f8(const Vec &v) { return 2 - std::cos(3.14*v.x) - std::cos(3.14*v.y); }
double dx8(const Vec &v) { return 3.14*std::sin(3.14*v.x); }
double dy8(const Vec &v) { return -3.14*std::sin(3.14*v.y); }


double error(double fk, double m) { return std::fabs(fk-m); }
