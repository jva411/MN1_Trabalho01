#include <iomanip>
#include "FunçõesAuxiliares.hpp"
using namespace std;

float* NewtonRaphsonFL(int num_lambdas, float* lambda, float* a3, float* a2, float* epsilon, float* d, int* iterMax){
    static float respostas[10];
    for(int i=0; i<num_lambdas; i++){
        int k = 0;
        int colWidth=20;
        //table header 
        cout << setfill('*') << setw(7*colWidth) << "*" << endl;
        cout << setfill(' ') << fixed;
        cout << setw(1.3*colWidth) << "Iteração" << setw(colWidth/1.4) << "x(k)" << setw(colWidth) <<  "F(x(k))" << setw(colWidth) << "FL" << setw(colWidth) << "x(k+1)" << setw(colWidth) << "F(x(k+1))" << endl; 
        cout << setfill('*') << setw(7*colWidth) << "*" << endl; 
        cout << setfill(' ') << fixed; 
        float xk = d[i];
        float Fxk, FdDx, xw, FL;
        bool flag = false;
        while(abs(calcularFuncao(d[i],a3[i],a2[i])) > epsilon[i] && k < iterMax[i])
        {
            FdDx = derivadaFuncao(d[i], a3[i], a2[i]);
            //Caso sem raiz
            if(abs(FdDx) < lambda[i] && k == 0)
            {
                cout << "Não foi possível calcular o valor com os dados do caso: " << i << endl;
                respostas[i] = false;
                flag = true;
                break;
            }
            else if(abs(FdDx) >= lambda[i])
            {
                FL = FdDx;
                xw = xk;
            }
            else
            {
                FL = derivadaFuncao(xw, a3[i], a2[i]);
            }
            xk = d[i] - calcularFuncao(d[i], a3[i], a2[i])/FL;
            Fxk = calcularFuncao(xk, a3[i], a2[i]);
            if(abs(Fxk) < epsilon[i] || abs(xk - d[i]) < epsilon[i]){
                cout << setw(colWidth) << k << setw(colWidth) << d[i] << setw(colWidth) <<  calcularFuncao(d[i],a3[i],a2[i]) << setw(colWidth) << FL << setw(colWidth) << xk << setw(colWidth) << Fxk << endl; 
                cout << setfill('*') << setw(7*colWidth) << "*" << endl;
                respostas[i] = xk;
                flag = true;
                break;
            }
            //Caso queira visualizar as informações de cada iteração, basta tirar o comentário da linha abaixo
            //cout << "k: " << k << "\n" << "a3: " << a3[i] << "\n" << "a2: " << a2[i] << "\n" << "d: " << d[i] << "\n" << "xk: " << xk << "\n" << "Fx: " << calcularFuncao(d[i],a3[i],a2[i]) << "\n" << "Fxk: " << Fxk << "\n" << "FdDx: " << FdDx << "\n" << "xw: " << xw << "\n" << "FL: " << FL << "\n";
            cout << setw(colWidth) << k << setw(colWidth) << d[i] << setw(colWidth) <<  calcularFuncao(d[i],a3[i],a2[i]) << setw(colWidth) << FL << setw(colWidth) << xk << setw(colWidth) << Fxk << endl;
            d[i] = xk;
            k++;
        }
        if(!flag){
            respostas[i] = d[i];
            cout << setw(colWidth) << k << setw(colWidth) << d[i] << setw(colWidth) <<  calcularFuncao(d[i],a3[i],a2[i]) << setw(colWidth) << FL << setw(colWidth) << xk << setw(colWidth) << Fxk << endl; 
            cout << setfill('*') << setw(7*colWidth) << "*" << endl;
        }
    }
    return respostas;
}