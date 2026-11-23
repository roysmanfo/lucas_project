#include "function.h"
#include "vec.h"
#include "gradient.h"
#include <iostream>

double f1(const Vec &v) { return (v.x * v.x + v.y * v.y) / 2.0; }

double dx1(const Vec &v) { return v.x; }

double dy1(const Vec &v) { return v.y; }

const double T = 0.1;
const int N = 100;

int main(int argc, char const *argv[]) {
  /*

   double a17 = 1.0 / 5.0;
    std::cout << "FUNZIONE 1" << '\n';
    for (int k = 0; (k <= N) && (gradient_norm(dx1(x,y), dy1(x,y)) >= T); k++)
    {
        // salva derivate prima aggiornare x e y
        double dx = dx1(x,y);
        double dy = dy1(x,y);

        x -= a17 * dx;
        y -= a17 * dy;

        bool isLast = (k==N) || (gradient_norm(dx1(x,y), dy1(x,y)) < T);

        // se iterazione ultima o multiplo 10
        if(k%10 == 0 || isLast)
        {
            // stampa k, valori x e y, funzione in pk, errore e norma del gradiente 
            std::cout << "k = "<< k << '\t'
                      << "x = " << x << '\t'<< "y = " << y << '\t' 
                      << "f = " << f1(x,y) <<'\t'
                      << "e = " << error(f1(x,y),m) << '\t' 
                      << gradient_norm(dx, dy)<< '\n';
        }
    }
    std::cout << "x = " << x << '\t'<< "y = " << y << '\t' << f1(x,y) << error(f1(x,y),m) << '\t' << gradient_norm(dx1(x,y), dy1(x,y))<< '\n';
    */
   
   Vec p(4, 4);
   
   Function f(f1, dx1, dy1);

  double a = 1.0 / 5.0;
  const double T = 0.1;
  const double N = 100;
  
  Vec grad = f.gradient(p);
  for (int i = 0; (i < N) && (grad.length() >= T); i++) {
    p -= a * grad;
    grad = f.gradient(p);
  }
  
  std::cout << "x = " << p.x 
            << "\ty = " << p.y 
            << "\tf(x, y)=" << f.evaluate(p) 
            // << "\terror=" << error(f.evaluate(p), 0)
            << "\tgrad_norm=" << grad.length()
            << std::endl;

  return 0;
}
