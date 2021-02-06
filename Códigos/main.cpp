//Guardas de inclusão

#include <iostream>
#include <math.h>
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
	
	//Teste NewtonFL (Ainda com pendências)
	float raiz = NewtonRaphsonFL(1,0.05,1,1,0.001,0.5,10);
	cout << "Raiz Aproximada: " << raiz << "\n";
}