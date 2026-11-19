#include <iostream>
#include "gradient.h"
#include "vec.h"

int main(int argc, char const *argv[])
{

    double x = 4; // p0
    double y = 4; // p0

    Vec p(x, y);

    double a = 1.0 / 5.0;
    const double T = 0.1;
    const double N = 100;

    Vec grad(dx1(x, y), dy1(x, y));

    for (int i = 0; (i < N) && (grad.length() >= T); i++)
    {
        x -= a * dx1(x, y);
        y -= a * dy1(x, y);
        Vec grad(dx1(x, y), dy1(x, y));
    }
    std::cout << "x = " << x << "  ";
    std::cout << "y = " << y << "  ";
    std::cout << "f(x,y) = " << f1(x, y) << std::endl;
    return 0;
}
