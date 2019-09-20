#include <iostream>
#include <cmath>
#include <vector>
#include <tuple> 
#include "functions.hpp"
using namespace std;

double fixPoint(vector<double> func, double error, int maxK){
    vector<double> isolatedFunc;
    double root;
    auto [isolatedFunc, root] = isolateGenericPolynomialFunction(func);
    int k = 0;
    double x;
    while(k < maxK){
        x = genericPolynomialFunction(isolatedFunc)
    }

}