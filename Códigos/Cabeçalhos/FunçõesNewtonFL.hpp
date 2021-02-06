//Guarda de inclusão
#include <math.h>

//Utilizada apenas para testes sem manipulação da função como string
float calcularFuncao(float d, float a3, float a2)
{
    return (pow((a3 * d),3) - (9*a2*d) + 3);
}

//Calculo da derivada enquanto não temos a função de cálculo automática
float derivadaFuncao(float d, float a3, float a2)
{
    return (3*a3*(pow(d,2)) - 9*a2);
}