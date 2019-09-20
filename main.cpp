#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>
#include "methods.hpp"
using namespace std;


int main() {
	Methods metodos;
	cout << "\n" << metodos.calculateFunction(2,2) << "\n";
	cout << "\n" << metodos.calculateFunctionDerivative(2,2) << "\n";
	return 0;
}
