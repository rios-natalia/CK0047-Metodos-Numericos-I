#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long double falsePosition(vector<double> func, double a, double b, double error1, double error2, int maxK){
    clock_t start, end; start = clock(); 
    long double x, fx, fa, fb, interval;
    int k = 0;
    interval = fabs(b-a);
    while(k < maxK){
        fa = genericPolynomialFunction(func, a);
        fb = genericPolynomialFunction(func, b);

        x = (a*fb - b*fa)/(fb-fa);
        fx = genericPolynomialFunction(func, x);
        // fabs => retorna o módulo do double passado

        if(fa*fb > 0){
            cout << "NÃO HÁ TROCA DE SINAL NO INTERVALO ESCOLHIDO! ABORTAR PROGRAMA!";
            return 0;
        }
        
        if(fabs(fx) < error2 || k > maxK){
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
        interval = fabs(b-a);
        if(interval <= error1){
            end = clock(); 
            cout<< "\nTEMPO DE EXECUÇÃO: " << 1000*(double(end - start) / double(CLOCKS_PER_SEC)) << "\n"; 
            return x;
        }
        k ++;
    }

    
    time(&end);
    return x;
    
}