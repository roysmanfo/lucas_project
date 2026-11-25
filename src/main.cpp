#include "function.h"
#include "gradient.h"
#include "vec.h"
#include <iostream>

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

void print_step(int k, const Vec &p, const Function &f, const Vec &grad) {
  printf("\tk=%-3d p_k=(%-2.4f,%-2.4f) f(p_k)=%-2.4f e_k=%.3e grad_norm=%.3e\n",
         k, p.x, p.y, f.evaluate(p), error(f.evaluate(p), f.get_known_min()),
         grad.length());
}

// Funzione che calcola il minimo tramite la tecnica "gradient descent"
// e stampa le varie iterazioni
void compute_f_min(const Function &f, const Vec &p0, double a, double T,
                   double N) {

  // Punto iniziale
  Vec p(p0.x, p0.y);

  // Vettore gradiente calcolato in P: (dx(p), dy(p))
  Vec grad = f.gradient(p);

  int k = 0;
  print_step(k, p, f, grad);

  while ((k < N) && (grad.length() >= T)) {
    p -= a * grad;        // Scendo verso la direzione opposta al gradiente
    grad = f.gradient(p); // Ricalcolo il gradiente per il nuovo punto

    k++;

    // k  p_k  f(p_k)  e_k  ||∇f(p_k)||
    if (k % 10 == 0) {
      print_step(k, p, f, grad);
    }
  }

  if (k % 10 != 0) {
    print_step(k, p, f, grad);
  }
}

int main(int argc, char const *argv[]) {
  const double T = 1e-3; // Soglia per la norma del gradiente
  const int N = 1000;    // Numero massimo di iterazioni

  // NOTA: Funzioni definite in gradient.cpp

  const Function F1(f1, dx1, dy1, 0);
  const Function F2(f2, dx2, dy2, 0);
  const Function F3(f3, dx3, dy3, 0);
  const Function F4(f4, dx4, dy4, 0);
  const Function F5(f5, dx5, dy5, 0);
  const Function F6(f6, dx6, dy6, 0);
  const Function F7(f7, dx7, dy7, 0);
  const Function F8(f8, dx8, dy8, 0);

  // f1
  std::cout << "f1 test 1 (a = 1/5):\n";
  compute_f_min(F1, Vec(4, 4), 1.0 / 5.0, T, N);
  std::cout << "f1 test 2 (a = 1/2):\n";
  compute_f_min(F1, Vec(-3, 2), 1.0 / 2.0, T, N);

  // f2
  std::cout << "f2 test 1 (a = 2/25):\n";
  compute_f_min(F2, Vec(1, 1), 2.0 / 25.0, T, N);
  std::cout << "f2 test 2 (a = 1/10):\n";
  compute_f_min(F2, Vec(-3, 1), 1.0 / 10.0, T, N);

  // f3
  std::cout << "f3 test 1 (a = 1/20):\n";
  compute_f_min(F3, Vec(1.4, 1.2), 1.0 / 20.0, T, N);
  std::cout << "f3 test 2 (a = 1/10):\n";
  compute_f_min(F3, Vec(-1.2, -0.8), 1.0 / 10.0, T, N);

  // f4
  std::cout << "f4 test 1 (a = 1/20):\n";
  compute_f_min(F4, Vec(1.4, -1.4), 1.0 / 20.0, T, N);
  std::cout << "f4 test 2 (a = 1/10):\n";
  compute_f_min(F4, Vec(0.5, -1.0), 1.0 / 10.0, T, N);

  // f5
  std::cout << "f5 test 1 (a = 3/20):\n";
  compute_f_min(F5, Vec(-0.5, 0.5), 3.0 / 20.0, T, N);
  std::cout << "f5 test 2 (a = 3/10):\n";
  compute_f_min(F5, Vec(1.5, -1.5), 3.0 / 10.0, T, N);

  // f6
  std::cout << "f6 test 1 (a = 3/10):\n";
  compute_f_min(F6, Vec(3, 3), 3.0 / 10.0, T, N);
  std::cout << "f6 test 2 (a = 1/2):\n";
  compute_f_min(F6, Vec(-4, 2), 1.0 / 2.0, T, N);

  // f7
  std::cout << "f7 test 1 (a = 1/5):\n";
  compute_f_min(F7, Vec(1, 1), 1.0 / 5.0, T, N);
  std::cout << "f7 test 2 (a = 2/5):\n";
  compute_f_min(F7, Vec(0.5, -0.5), 2.0 / 5.0, T, N);

  // f8
  std::cout << "f8 test 1 (a = 1/10):\n";
  compute_f_min(F8, Vec(0.5, 0.5), 1.0 / 10.0, T, N);
  std::cout << "f8 test 2 (a = 3/20):\n";
  compute_f_min(F8, Vec(-0.8, 1.3), 3.0 / 20.0, T, N);

  return 0;
}
