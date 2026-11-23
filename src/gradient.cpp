#include "gradient.h"
#include <cmath>

double f1(double x, double y) { return (x * x + y * y) / 2.0; }

double dx1(double x, double) { return x; }

double dy1(double, double y) { return y; }

double f2(double x, double y) { return (x * x + 16*y * y) / 2.0; }
double dx2(double x, double) { return x; }
double dy2(double, double y) { return 16*y; }

double f3(double x, double y) { return pow((x * x -1),2) + y*y; }
double dx3(double x, double) { return 2*2*x*(x*x-1); }
double dy3(double, double y) { return 2*y; }

double f4(double x, double y) { return pow((x * x -1),2) + y*y + std::pow((x-1),2)/5; }
double dx4(double x, double) { return (2*2*x*(x*x-1)) + (2.0/5.0)*(x-1); }
double dy4(double, double y) { return 2*y; }

double f5(double x, double y) { return 4*std::pow(std::sinh(x/2.0),2) + std::pow(y,2); }
double dx5(double x, double) { return 4*std::sinh(x/2.0)*std::cosh(x/2.0); }
double dy5(double x, double y) { return 2*y; }

double f6(double x, double y) { return std::log(1 + x*x + y*y); }
double dx6(double x, double y) { return (2*x)/((1 + x*x + y*y)); }
double dy6(double x, double y) { return (2*y)/((1+x*x+y*y)); }

double f7(double x, double y) { return 1 - std::exp(-(x*x+y*y)); }
double dx7(double x, double y) { return -std::exp(-(x*x+y*y))*(-2*x); }
double dy7(double x, double y) { return -std::exp(-(x*x+y*y))*(-2*y); }

double f8(double x, double y) { return 2 - std::cos(3.14*x) - std::cos(3.14*y); }
double dx8(double x, double y) { return 3.14*std::sin(3.14*x); }
double dy8(double x, double y) { return -3.14*std::sin(3.14*y); }

double gradient_norm(double dx, double dy)
{
    return std::sqrt(dx * dx + dy * dy);
}

double error(double fk, double m)
{
    return std::abs(fk-m);
}