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
	/*
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
	cout << "Digite um chute inicial: ";
	cin >> x0;
	
	double res = metodos.calculateByNewtonRhapson(x0, 0.000001, 0.000001, 100, 1);
	
	if(res == -1){
		cout << "Um erro ocorreu, cheque os parâmetros de entrada!\n\n";
	}
	else{
		cout << "A resposta aproximada é: " << res << "\n\n";
	}*/

	Answer resposta = metodos.calculateByNewtonRhapson(1e+21,0.000001, 0.000001, 1000, 50);
	if(resposta.getErrorFlag()){
		cout << "\nUm erro ocorreu!\n" << resposta.getErrorMessage() << "\n\n";
	}
	else{
		cout << "\nCálculo da função concluída!";
		cout << "\nResposta aproximada: " << resposta.getResult();
		cout << "\nNúmero de iterações: " << resposta.getIterations();
		cout << "\nTempo: " << resposta.getTime() << "\n\n";
		
	}
	
	return 0;
}
