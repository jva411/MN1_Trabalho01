#include <cmath>
using namespace std;

float calcularFuncao(float d, float a3, float a2);

double derivadaFuncao(float d, float a3, float a2){
    // Fórmula da derivada central com erro:
    // F'(x) = (f(x + deltaX) + f(x))/deltaX
    //
    // com deltaX=1, temos que o erro é exatamente 3.a.x + a + b  onde f(x) = ax³ + bx² +cx + d
    // prova do cálculo na imagem
    //
    // temos x=d, a=a3, b=0, c=9.a2, d=3
    // fórmula da oscilação do pêndulo: f(d) = a3.d³ - 9.a2.d + 3

    double fx1 = calcularFuncao(d+1, a3, a2);
    double fx = calcularFuncao(d, a3, a2);
    double erro = 3*a3*d + a3;
    return (fx1 - fx) - erro;
}