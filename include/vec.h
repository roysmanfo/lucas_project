#ifndef VEC_H
#define VEC_H
class Vec
{
public:
    Vec();
    Vec(double x, double y);

    double getX() const;
    double getY() const;

    double length() const;
    double dot(const Vec &v) const;

private:
    double x;
    double y;
};

Vec operator+(const Vec a, const Vec b);
Vec operator-(const Vec &a, const Vec &b);
Vec operator*(const Vec &a, const double d);
double dot(const Vec &a, const Vec &b);

#endif