//Guarda de inclusão
#include <iostream>
#include <math.h>
#include "FunçõesNewtonFL.hpp"
using namespace std;

//Método de Newton com adaptações para os casos em que f'(xk) = 0, número máximo de casos de teste = 10 (TENTAR CONTORNAR ISSO);
float* NewtonRaphsonFL(int num_lambdas, float* lambda, float* a3, float* a2, float* epsilon, float* d, int* iterMax){
    static float respostas[10];
    for(int i=0; i<num_lambdas; i++){
        float Fd = calcularFuncao(d[i], a3[i], a2[i]);
        if(abs(Fd) < epsilon[i])
        {
            respostas[i] = d[i];
            continue;
        }
        int k = 0;
        float xk, Fxk, FdDx, xw, FL;
        while(k < iterMax[i])
        {
            //Valor inicial de xk, onde k  == 0;
            if(k == 0)
            {
                xk = d[i];
            }
            FdDx = derivadaFuncao(d[i], a3[i], a2[i]);
            if(abs(FdDx) < lambda[i] && k == 0)
            {
                cout << "Não foi possível calcular o valor com os dados do caso: " << i << endl;
                break;
            }
            else if(abs(FdDx) > lambda[i])
            {
                FL = FdDx;
                xw = xk;
            }
            else
            {
                FL = derivadaFuncao(xw, a3[i], a2[i]);
            }
            
            xk = d[i] - Fd/FL;
            Fxk = calcularFuncao(xk, a3[i], a2[i]);

            if(abs(Fxk) < epsilon[i]){
                respostas[i] = xk;
                break;
            }
            d[i] = xk;
            Fd = calcularFuncao(d[i], a3[i], a2[i]);
            k++;
        }
        //respostas[i] = false; (OBSERVAR COMPORTAMENTO)
    }
    return respostas;
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
//respostas = Vetor com todos os valores dos casos de teste;