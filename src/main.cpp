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

const double T = 0.1; // Soglia per la norma del gradiente
const int N = 100;    // Numero massimo di iterazioni

// Funzione che calcola il minimo tramite la tecnica "gradient descent"
// e stampa
// - x e y del punto di minimo
// - la funzione calcolata in quel punto
// - L'errore rispetto al minimo reale
void compute_f_min(Function f, const Vec &initial_point, double known_min,
                   double a, double T, double N) {

  // Punto iniziale
  Vec p(initial_point.x, initial_point.y);

  // Vettore gradiente calcolato in P: (dx(p), dy(p))
  Vec grad = f.gradient(p);
  for (int i = 0; (i < N) && (grad.length() >= T); i++) {
    p -= a * grad;        // Scendo verso la direzione del gradiente
    grad = f.gradient(p); // Ricalcolo il gradiente per il nuovo punto
  }

  std::cout << "x=" << p.x << "\ty=" << p.y << "\tf(x,y)=" << f.evaluate(p)
            << "\terror=" << error(f.evaluate(p), known_min)
            << "\tgrad_norm=" << grad.length() << std::endl;
}

int main(int argc, char const *argv[]) {
  // NOTA: Funzioni definite in gradient.cpp

  std::cout << "f1: ";
  compute_f_min(Function(f1, dx1, dy1), Vec(4, 4), 0, 1.0 / 5.0, 1, 100);

  std::cout << "f2: ";
  compute_f_min(Function(f2, dx2, dy2), Vec(1, 1), 0, 1.0 / 5.0, 1, 100);

  std::cout << "f3: ";
  compute_f_min(Function(f3, dx3, dy3), Vec(1, 1), 0, 1.0 / 5.0, 1, 100);

  return 0;
}
