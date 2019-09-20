#include <iostream>
#include <vector>
#include <tuple> 
#include <cmath>
#include "functions.hpp"
#include "bissection.hpp"
#include "falsePosition.hpp"

using namespace std;

int main() {
  vector<double> v {1,0,-9,3};
  //cout << "\n\n\nResultado: " << bissection(v, 0,1, 0.001, 100);
  //cout << "\n\n\nResultado: " << falsePosition(v, 0,1, 0.0005,0.0005, 100);
  
  //tuple<vector<double>, double> t = isolateGenericPolynomialFunction(v);
  //cout << get<0>(t)[0] << get<0>(t)[1] << get<0>(t)[2] << get<0>(t)[3] << " | " << get<1>(t);

  //tuple<char, int> t = make_tuple('a', 1);

  return 0;
}
