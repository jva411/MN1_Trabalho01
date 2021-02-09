//Guarda de inclusão

#include <iostream>
#include <math.h>
#include "FunçõesNewtonRaphson.hpp"
using std::cout;

float NewtonRaphson(float x0, float epsilon1, float epsilon2, int iterMax){
    float Fx0 = calcularFuncao(x0);
    if(abs(Fx0) < epsilon1){
        return x0;
    }
    int k = 0;
    float x1, Fx1, Fx0Dx;
    while(k < iterMax){
        Fx0Dx = calcularDerivada(x0);
        x1 = x0 - Fx0/Fx0Dx;
        Fx1 = calcularFuncao(x1);
        if(abs(Fx1) < epsilon1 || abs(x1-x0) < epsilon2){
            return x1;
        }
        //Caso queira visualizar as informações de cada iteração, basta tirar o comentário da linha abaixo
        //cout << "k: " << k << "\n" << "x1: " << x1 << "\n" << "Fx1: " << Fx1 << "\n" << "Fx0: " << Fx0 << "\n";
        x0 = x1;
        Fx0 = calcularFuncao(x0);
        k++;
    }
    return 0;
}