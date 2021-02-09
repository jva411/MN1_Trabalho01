//Guarda de inclusão
#include <math.h>

//Defina anteriormente as funções que serão utilizadas 
float calcularFuncao(float x){
    //Função para calculo de F(x);
    return (x - (x * log(x)));
}

float calcularDerivada(float x){
    //F'(x) para calculos
    return -log(x);
}