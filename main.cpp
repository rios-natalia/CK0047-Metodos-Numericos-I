#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>
#include "methods.hpp"
using namespace std;


int main() {
	Methods metodos;
	/*
	for(int a = -5; a < 6; a++){
		vector<double> resposta = metodos.calculateFunctionInterval(a);
		cout << "\n\n\nPara a = " << a << " temos: \n" << resposta[0] << "  " << resposta[1];
	}*/
	
	double a;
	cout << "Digite o valor de A: ";
	cin  >> a;
	double e1, e2;
	cout << "Digite o valor da precisao epislon 1: ";
	cin >> e1;
	cout << "Digite o valor da precisao epislon 2: ";
	cin >> e2;
	double maxK = 1000;
	double selectedOption;
	
	cout << "Deseja estabelecer um número máximo de iterações?\n1- Sim\n2- Não (Usar 1000)";
	cin >> selectedOption;
	if(selectedOption == 1){
		cout << "Digite o número máximo de iterações a ser utilizado: ";
		cin >> maxK;
	}
	
	double x0;
	cout << "Digite um chute inicial";
	cin >> x0;
	
	double res = metodos.calculateByNewtonRhapson(x0, e1, e2, maxK, a);
	cout << "A resposta aproximada é: " << res;

	return 0;
}
