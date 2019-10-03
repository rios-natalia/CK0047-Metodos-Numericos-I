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
	double e;
	cout << "Digite o valor da precisao: ";
	cin >> e;
	double maxK = 1000;
	double selectedOption;
	cout << "Deseja estabelecer um número máximo de iterações?\n1- Sim\n2- Não (Usar 1000)";
	cin >> selectedOption;
	if(selectedOption == 1){
		cout << "Digite o número máximo de iterações a ser utilizado: ";
		cin >> maxK;
	}
	cout << "Deseja estabelecer um intervalo?\n1- Sim\n2- Não (Calcular automaticamente)";
	cin >> selectedOption;
	if(selectedOption == 1){
		double intA, intB;
		cout << "Digite o limite inferior do intervalo: ";
		cin >> intA;
		cout << "Digite o limite superior do intervalo: ";
		cin >> intB;
		double res = metodos.calculateByBissection(intA, intB, e, maxK, a);
		cout << "A resposta aproximada é: " << res;
	}
	else if(selectedOption == 2){
		double res = metodos.calculateByBissectionNoInterval(e, maxK, a);
		cout << "A resposta aproximada é: " << res;
	}

	return 0;
}
