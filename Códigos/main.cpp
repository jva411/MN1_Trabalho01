//Guardas de inclusão

#include <iostream>
#include <math.h>
#include <array>
#include "Cabeçalhos/NewtonFL.hpp"
using namespace std;

int main()
{
	cout << "\t\t -------------- Trabalho 01 - Métodos Numéricos -------------- " << "\n";
	cout << "\t\t Aluno: Carlos Eduardo \t\t\tMatrícula: 475107 "  << "\n";
	cout << "\t\t Aluno: Gabriel Passos \t\t\tMatrícula: 470692 "  << "\n";
	cout << "\t\t Aluno: João Gabriel  \t\t\tMatrícula: 472078 "  << "\n";
	cout << "\t\t Aluno: João Victor \t\t\tMatrícula: 473977 "  << "\n";
	cout << "\t\t Aluna: Laura Petrola  \t\t\tMatrícula: 471913 "  << "\n";
	cout << "\t\t ------------------------------------------------------------- " << "\n";
	
	//Variáveis úteis para o Método NewtonFL
	int num_lambdas;

	//Coletando informações para o Método NewtonFL
	cout << "Digite a quantidade de λ's que será utilizado: ";
	cin >> num_lambdas;
	float a2[num_lambdas], a3[num_lambdas], lambdas[num_lambdas], epsilons[num_lambdas], d[num_lambdas]; int iterMax[num_lambdas];
	for(int i=1; i<=num_lambdas;i++){
		cout << "----------------- " << i << "º Iteração -----------------" << endl;
		cout << "Digite o valor da " << i << "º opção de λ: ";
		cin >> lambdas[i-1];
		cout << "Digite o valor de a2 para a " << i << "º opção de λ: ";
		cin >> a2[i-1];
		cout << "Digite o valor de a3 para a " << i << "º opção de λ: ";
		cin >> a3[i-1];
		cout << "Digite o valor de ε para a " << i << "º opção de λ: ";
		cin >> epsilons[i-1];
		cout << "Digite o valor de d para a " << i << "º opção de λ: ";
		cin >> d[i-1];	
		cout << "Digite o valor máximo de iterações para a " << i << "º opção de λ: ";
		cin >> iterMax[i-1];
	}

	//Teste NewtonFL (Ainda com pendências)
	float* raiz = NewtonRaphsonFL(num_lambdas,lambdas,a3,a2,epsilons,d,iterMax);
	for(int i=1; i<=num_lambdas;i++){
		cout << "----------------- " << i << "º Caso de Teste -----------------" << endl;
		cout << "Raiz Aproximada: " << raiz[i-1] << "\n";
	}
}