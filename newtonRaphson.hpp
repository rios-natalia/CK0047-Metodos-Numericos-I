#include <iostream>
#include <vector>
#include <cmath>

#include "functions.hpp"
#include "methods.hpp"

using namespace std;

double newtonRaphson(vector<double> func, double x0, double epsilon1, double epsilon2, int maxK)
{

  clock_t start, end; start = clock();
  Methods methods;
  double fx = genericPolynomialFunction(func, x0);
  int k = 0;

  if(abs(fx) < epsilon1)
    return x0;

  while(k < maxK)
  {
    double x1 = x0 - genericPolynomialFunction(func, x0)/methods.calculateFunctionDerivative(x0);
    if(abs(genericPolynomialFunction(func, x1)) < epsilon1 || abs(x1-x0) < epsilon2)
    {
      end = clock(); 
      cout<< "\nTEMPO DE EXECUÇÃO: " << 1000*(double(end - start) / double(CLOCKS_PER_SEC)) << "\n"; 
      return x1;
    }
    x0 = x1;
    k++;
  }

  time(&end);
  return x0;
}
