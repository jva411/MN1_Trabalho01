float calcularFuncao(float d, float a3, float a2){
    return (a3 * pow(d,3) - (9*a2*d) + 3);
}

double derivadaFuncao(float d, float a3, float a2){
    double fx1 = calcularFuncao(d+1, a3, a2);
    double fx = calcularFuncao(d, a3, a2);
    double erro = 3*a3*d + a3;
    return (fx1 - fx) - erro;
}
