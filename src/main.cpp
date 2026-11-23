#include <iostream>
#include "gradient.h"
#include "vec.h"

const double T = 0.1;
const int N = 100;

int main(int argc, char const *argv[])
{
    // fa inizializza x y
    double x = 4; // p0
    double y = 4; // p0

    // m = minimo della funzione
    const double m = 0;


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


    double a2 = 2.0 / 25.0;
    std::cout << "FUNZIONE 2"<< '\n';
    for (int k = 0; (k <= N) && (gradient_norm(dx2(x,y), dy2(x,y)) >= T); k++)
    {
        // salva derivate prima aggiornare x e y
        double dx = dx2(x,y);
        double dy = dy2(x,y);
        
        x -= a2 * dx;
        y -= a2 * dy;

        bool isLast = (k==N) || (gradient_norm(dx1(x,y), dy1(x,y)) < T);

        // se iterazione ultima o multiplo 10
        if(k%10 == 0 || isLast)
        {
            // stampa k, valori x e y, funzione in pk, errore e norma del gradiente 
            std::cout << "k = "<< k << '\t'
                      << "x = " << x << '\t'<< "y = " << y << '\t' 
                      << "f = " << f2(x,y) <<'\t'
                      << "e = " << error(f2(x,y),m) << '\t' 
                      << gradient_norm(dx, dy)<< '\n';
        }
    }
    double a34 = 1.0 / 20.0;
    double a5 = 3.0 / 20.0;
    double a6 = 3.0 / 10.0;
    double a8 = 1.0 / 10.0;


    
    return 0;
}
