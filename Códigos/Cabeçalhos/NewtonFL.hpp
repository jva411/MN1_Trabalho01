//Guarda de inclusão
#include <iostream>
#include <math.h>
#include "FunçõesNewtonFL.hpp"
using namespace std;

//Pendências parem serem resolvidas: 
//1 - Número de lambdas?? Como utilizar isso? (Perguntar pro Bento);
//2 - Opções de a3 e a2 para cada lambda?? (Perguntar pro Bento);
//3 - Como calcular iterMax;

//Método de Newton com adaptações para os casos em que f'(xk) = 0
float NewtonRaphsonFL(int num_lambdas, float lambda, float a3, float a2, float epsilon, float d, int iterMax){
    float Fd = calcularFuncao(d, a3, a2);
    if(abs(Fd) < epsilon)
    {
        return d;
    }
    int k = 0;
    float xk, Fxk, FdDx, xw, FL;
    
    while(k < iterMax)
    {
        //Valor inicial de xk, onde k  == 0;
        if(k == 0)
        {
            xk = d;
        }
        FdDx = derivadaFuncao(d, a3, a2);
        if(abs(FdDx) < lambda && k == 0)
        {
            cout << "Não foi possível calcular o valor." << endl;
        }
        else if(abs(FdDx) > lambda)
        {
            FL = FdDx;
            xw = xk;
        }
        else
        {
            FL = derivadaFuncao(xw, a3, a2);
        }
        
        xk = d - Fd/FL;
        Fxk = calcularFuncao(xk, a3, a2);

        if(abs(Fxk) < epsilon){
            return xk;
        }
        d = xk;
        Fd = calcularFuncao(d, a3, a2);
        k++;
    }
    return 0;
}

//Explicação das variáveis

//Fd = Valor assumido por f(d);
//k = Contador do while;
//xk = Aproximação nova;
//Fxk = Valor assumido por f(xk), ou seja, nova aproximação;
//FdDx = Derivada do valor assumido por f(d);
//xw = Backup do último valor xk válido;
//FL = Função especificada pela questão;
//iterMax = Número de iteracões máximas;
//d = Alterar o valor da nova variável;

