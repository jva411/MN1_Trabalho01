#include<iomanip>
using namespace std;
float NewtonRaphson(float x0, float epsilon1, float epsilon2, int iterMax, float a2, float a3){
    int k = 1;
    int colWidth=20;
    //table header 
    cout << setfill('*') << setw(7*colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(1.3*colWidth) << "Iteração" << setw(colWidth/1.4) << "x0" << setw(colWidth) <<  "F(x0)" << setw(colWidth) << "F'(x0)" << setw(colWidth) << "x1" << setw(colWidth) << "F(x1)" << endl; 
    cout << setfill('*') << setw(7*colWidth) << "*" << endl; 
    cout << setfill(' ') << fixed; 
    float x1;
    while (abs(calcularFuncao(x0,a3,a2)) > epsilon1 && k <= iterMax){
        x1 = x0 - (calcularFuncao(x0,a3,a2)/derivadaFuncao(x0,a3,a2));

        if(abs(calcularFuncao(x1,a3,a2)) < epsilon1 || abs(x1 - x0) < epsilon2){
            cout << setw(colWidth) << k << setw(colWidth) << x0 << setw(colWidth) <<  calcularFuncao(x0,a3,a2) << setw(colWidth) << derivadaFuncao(x0,a3,a2) << setw(colWidth) << x1 << setw(colWidth) << calcularFuncao(x1,a3,a2) << endl; 
            cout << setfill('*') << setw(7*colWidth) << "*" << endl;
            return x1;
        }
        cout << setw(colWidth) << k << setw(colWidth) << x0 << setw(colWidth) <<  calcularFuncao(x0,a3,a2) << setw(colWidth) << derivadaFuncao(x0,a3,a2) << setw(colWidth) << x1 << setw(colWidth) << calcularFuncao(x1,a3,a2) << endl; 
        k += 1;
        x0 = x1;
    }
    return x0;
}