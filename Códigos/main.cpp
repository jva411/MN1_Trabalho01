#include <iostream>
#include <cmath>
#include "Cabeçalhos/NewtonFL.hpp"
#include "Cabeçalhos/NewtonRaphson.hpp"
using namespace std;
int main()
{
	int decisao;
	//Inicialização
	cout << "\t\t\t -------------- Trabalho 01 - Métodos Numéricos -------------- " << "\n";
	cout << "\t\t\t Aluno: Carlos Eduardo \t\t\tMatrícula: 475107 "  << "\n";
	cout << "\t\t\t Aluno: Gabriel Passos \t\t\tMatrícula: 470692 "  << "\n";
	cout << "\t\t\t Aluno: João Gabriel  \t\t\tMatrícula: 472078 "  << "\n";
	cout << "\t\t\t Aluno: João Victor \t\t\tMatrícula: 473977 "  << "\n";
	cout << "\t\t\t Aluna: Laura Petrola  \t\t\tMatrícula: 471913 "  << "\n";
	cout << "\t\t\t ------------------------------------------------------------- " << "\n";
	
	//Escolha do método para resolução
	cout << "\n\t\t\t -------------- Iteração/Coleta de dados - Usuário: ----------\n";
	cout << "Escolha o método que será utilizado para consultar a raíz do seu problema: " << "\n";
    cout << "1: Método de NewtonRaphson Original" << "\n" << "2: Método de NewtonFL" << "\n";
	cout << "Número: ";
    cin >> decisao;
    switch(decisao){
		//Algoritmo - NewtonRaphson Original
		case 1:
			//Variáveis úteis para o Método NewtonRaphson Original
			float epsilon, epsilon1, aproximInicial, raizNr, a3, a2;
			int maxIter;
			cout << "Digite o valor do erro aproximado (1): ";
            cin >> epsilon;
            cout << "Digite o valor do erro aproximado (2): ";
            cin >> epsilon1;
            cout << "Digite o valor para a aproximação inicial x0: ";
            cin >> aproximInicial;
			cout << "Digite o valor de iterações máximas: ";
            cin >> maxIter;
			cout << "Digite o valor de a2: ";
			cin >> a2;
			cout << "Digite o valor de a3: ";
			cin >> a3;
			cout << "\n";
            cout << "\t\t\t -------------- Algoritmo de Newton-Raphson: ----------------\n";
            raizNr = NewtonRaphson(aproximInicial,epsilon,epsilon1,maxIter,a2,a3);
			cout << "\n";
			cout << "\t\t\t -------------- Resolução Newton-Raphson: ------------------\n";
            cout << "Raiz Aproximada: " << raizNr << "\n";
			if(raizNr > 0.3){
					cout << "Deslocamento > 0.3 centímetros. Logo o pêndulo romperá!" << endl;
				}
            break;
		
		//Algoritmo - Método NewtonFL
		case 2:
		{ 
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
			float* raiz = NewtonRaphsonFL(num_lambdas,lambdas,a3,a2,epsilons,d,iterMax);
			for(int i=1; i<=num_lambdas;i++){
				cout << "----------------- " << i << "º Caso de Teste -----------------" << endl;
				cout << "Raiz Aproximada: " << raiz[i-1] << "\n";
				if(raiz[i -1] > 0.3){
					cout << "Deslocamento > 0.3 centímetros. Logo o pêndulo romperá!" << endl;
				}
			}
			break;
		}
		//Erro
		default:
			cout << "Valor inválido" << "\n";
			break;
		}
}