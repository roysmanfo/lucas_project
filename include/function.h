#ifndef FUNCTION_H
#define FUNCTION_H
#include "vec.h"

/*
 * Funge da contenitore per i puntatori alle funzioni
 * oltre ad offrire metodi per valutare la funzione in un punto e per calcolare
 * il gradiente.
 *
 * Leggere il main per altri dettagli sul perché di questa scelta.
 */
class Function {
public:
  Function(double (*f)(const Vec &p), double (*dx)(const Vec &p),
           double (*dy)(const Vec &p));

  /* Esegue f(p) */
  double evaluate(const Vec &p);

  /* Restituisce (dx(p), dy(y)) */
  Vec gradient(const Vec &p);

private:
  double (*f)(const Vec &p);
  double (*dx)(const Vec &p);
  double (*dy)(const Vec &p);
};

#endif
