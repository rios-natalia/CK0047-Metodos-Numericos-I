#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double bissection(vector<double> func, double a, double b, double error, int maxK){clock_t start, end; start = clock(); double x, fx, fa, fb, interval;int k = 0;
    interval = fabs(b-a);
    while(k < maxK){
        x = (a+b)/2;
        fx = genericPolynomialFunction(func, x);
        fa = genericPolynomialFunction(func, a);
        fb = genericPolynomialFunction(func, b);
        // fabs => retorna o módulo do double passado

        if(fa*fb > 0){
            return 0;
        }
        if(interval <= error){
            end = clock(); 
            cout<< "\nTEMPO DE EXECUÇÃO: " << 1000*(double(end - start) / double(CLOCKS_PER_SEC)) << "\n"; 
            return x;
        }
        if(fx*fa < 0){
            b = x;
        }
        else if(fx*fb < 0){
            a = x;
        }
        interval = interval / 2;
        k ++;
    }

    
    time(&end);
    return x;
    
}