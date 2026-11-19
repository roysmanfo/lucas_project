#include "gradient.h"
#include <cmath>

double f1(double x, double y)
{
    return (x * x + y * y) / 2.0;
}

double dx1(double x, double)
{
    return x;
}

double dy1(double, double y)
{
    return y;
}

double gradient_norm(double dx, double dy)
{
    return sqrt(dx * dx + dy * dy);
}
