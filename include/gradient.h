#ifndef GRADIENT_H
#define GRADIENT_H

#include <vec.h>

double f1(const Vec &v);
double dx1(const Vec &v);
double dy1(const Vec &v);

double f2(const Vec &v);
double dx2(const Vec &v);
double dy2(const Vec &v);

double f3(const Vec &v);
double dx3(const Vec &v);
double dy3(const Vec &v);

double f4(const Vec &v);
double dx4(const Vec &v);
double dy4(const Vec &v);

double f5(const Vec &v);
double dx5(const Vec &v);
double dy5(const Vec &v);

double f6(const Vec &v);
double dx6(const Vec &v);
double dy6(const Vec &v);

double f7(const Vec &v);
double dx7(const Vec &v);
double dy7(const Vec &v);

double f8(const Vec &v);
double dx8(const Vec &v);
double dy8(const Vec &v);

// Calcola la differenza in valore assoluto tra il valore ottenuto (k) e il
// minimo previsto (m)
double error(double k, double m);
#endif
