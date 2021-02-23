using namespace std;
float NewtonRaphson(float x0, float epsilon1, float epsilon2, int iterMax, float a2, float a3){
    int k = 1;
    float x1;
    while (abs(calcularFuncao(x0,a3,a2)) > epsilon1 && k <= iterMax){
        x1 = x0 - (calcularFuncao(x0,a3,a2)/derivadaFuncao(x0,a3,a2));

        if(abs(calcularFuncao(x1,a3,a2)) < epsilon1 || abs(x1 - x0) < epsilon2) return x1;

        x0 = x1;

        k += 1;
    }
    return x0;
}