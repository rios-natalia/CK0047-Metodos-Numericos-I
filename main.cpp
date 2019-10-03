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
	vector<double> resposta = metodos.calculateFunctionInterval(8);
	cout << "\n\n\nPara a = " << 8 << " temos: \n" << resposta[0] << "  " << resposta[1];
	
	return 0;
}
