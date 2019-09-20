#include <iostream>
#include <vector>
#include <math.h>
#include<tuple> // for tuple 
using namespace std;

double genericPolynomialFunction(vector<double> coeficients , double x){
    
    double result = 0;
    for(int i = coeficients.size()-1; i >= 0; i--){
        result += coeficients[i]*pow(x,coeficients.size()-1-i);
    }
    
    return result;
}

tuple<vector<double>, double> isolateGenericPolynomialFunction(vector<double> coeficients){
    vector<double> copy = coeficients;
    int isolatedCoeficient;
    for(int i = 0; i < coeficients.size()-2; i++){
        if(coeficients[i] != 0){
            isolatedCoeficient = coeficients.size()-1-i;
            copy[i] = 0;
            break;
        }
    }
    return make_tuple(copy, isolatedCoeficient);

}