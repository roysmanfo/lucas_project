#include "function.h"
#include "gradient.h"
#include "vec.h"
#include <iostream>
#include <random>

/*
 * Nota sulle scelte strutturali del programma:
 * Il programma implementa l'algoritmo "gradient descent" applicandolo a diverse
 * funzioni matematiche a 2 variabili. Per rendere il codice pulito e simile
 * alla notazione matematica abbiamo adottato 2 scelte principali:
 *
 * 1. Invece di gestire separatamente le coordinate x e y abbiamo implemntato
 * uno struct "Vec". L'overload degli operatori ci permette di scrivere
 * operazioni vettoriali come p -= a * grad in modo naturale
 *
 * 2. Creare una classe Function che accettasse puntatori a funzioni.
 * Inizialmente avevamo valutato un approccio con polimorfosmo con classe base
 * astratta e sottoclasse per ogni funzione, simile agli approcci Java.
 * Tuttavia, questa soluzione avrebbe introdotto codice ripetitivo e la
 * necessità di gestire l'allocazione. Richiamando alcune conoscenze personali,
 * abbiamo pensato di utilizzare dei puntatori a funzione. Una classe "Function"
 * riceve nel costruttore i riferimenti alla funzione definita e alle sue
 * derivate parziali Questo rende il codice più compatto e rende visibile
 * chiaramente l'implementazione delle funzioni.
 */

// Funzione che calcola il minimo tramite la tecnica "gradient descent"
// e stampa le varie iterazioni
void compute_f_min(const Function &f, const Vec &domain, double a, double T,
                   double N) {

  // Punto iniziale

  double lower_bound = domain.x;
  double upper_bound = domain.y;
  Vec p(domain.x, domain.y);

  // Vettore gradiente calcolato in P: (dx(p), dy(p))
  Vec grad = f.gradient(p);
  int k;
  for (k = 1; (k < N) && (grad.length() >= T); k++) {
    Vec update = a * grad;
    p -= update;          // Scendo verso la direzione opposta al gradiente
    grad = f.gradient(p); // Ricalcolo il gradiente per il nuovo punto

    // k  p_k  f(p_k)  e_k  ||∇f(p_k)||
    if (k % 10 == 0) {
      printf("\tk=%-3d p_k=(%-2.4f,%-2.4f) f(p_k)=%-2.4f e_k=%-2.4f "
             "grad_norm=%-2.4f\n",
             k, p.x, p.y, f.evaluate(p),
             error(f.evaluate(p), f.get_known_min()), grad.length());
    }
  }

  printf(
      "\tk=%-3d p_k=(%2.4f,%-2.4f) f(p_k)=%-2.4f e_k=%-2.4f grad_norm=%-2.4f\n",
      k, p.x, p.y, f.evaluate(p), error(f.evaluate(p), f.get_known_min()),
      grad.length());
}

int main(int argc, char const *argv[]) {
  const double T = 1e-3; // Soglia per la norma del gradiente
  const int N = 1000;    // Numero massimo di iterazioni

  // NOTA: Funzioni definite in gradient.cpp

  std::cout << "f1: ";
  compute_f_min(Function(f1, dx1, dy1, 0), Vec(-4, 4), 1.0 / 5.0, T, N);

  std::cout << "f2: ";
  compute_f_min(Function(f2, dx2, dy2, 0), Vec(-4, 4), 2.0 / 25.0, T, N);

  std::cout << "f3: ";
  compute_f_min(Function(f3, dx3, dy3, 0), Vec(-1.5, 1.5), 1.0 / 20.0, T, N);

  std::cout << "f4: ";
  compute_f_min(Function(f4, dx4, dy4, 0), Vec(-1.5, 1.5), 1.0 / 20.0, T, N);

  std::cout << "f5: ";
  compute_f_min(Function(f5, dx5, dy5, 0), Vec(-0.5, 0.5), 3.0 / 20.0, T, N);

  std::cout << "f6: ";
  compute_f_min(Function(f6, dx6, dy6, 0), Vec(-2, 2), 3.0 / 10.0, T, N);

  std::cout << "f7: ";
  compute_f_min(Function(f7, dx7, dy7, 0), Vec(-1.5, 1.5), 1.0 / 5.0, T, N);

  std::cout << "f8: ";
  compute_f_min(Function(f8, dx8, dy8, 0), Vec(-4, 4), 1.0 / 10.0, T, N);

  return 0;
}
