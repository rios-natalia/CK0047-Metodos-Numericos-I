#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
class Methods{
	private:
		double rocketFunction(double d, double a=1){
			return (a*d) - ( d * log(d) );				
		};
		double rocketFunctionDerivative(double d, double a=1){
			return -1*log(d) + a -1;
		};

		vector<double> getInterval(double a=1){
			double index = 0.000001; // 2 ^ pequeno
			double index2 = 1; // 2 ^ 0

			double changed = rocketFunction(index, a)*rocketFunction(index2, a);
			
			while(changed > 0){
				if(index == 0.000001){
					index = 1;
					index2 = 2;
				}
				else{
					index = index*2;
					index2 = index2*2;
				}
				changed = rocketFunction(index, a)*rocketFunction(index2, a);
			}

			vector <double> result;
			result.push_back(index);
			result.push_back(index2);
			return result;
		};
	public:
		double calculateFunction(double d, double a=1){
			return rocketFunction(d,a);
		};
		double calculateFunctionDerivative(double d, double a=1){
			return rocketFunctionDerivative(d, a);
		};
		vector<double> calculateFunctionInterval(double a=1){
			return getInterval(a);
		}

		// A, B e maxK podem ou não ser entradas
		// Error é uma entrada (precisão)
		// Não confundir funA (a constante da função) com a (início do intervalo)
		double calculateByBissection(double a, double b, double error, int maxK, double funA = 1){
			cout << "Calculando com : \n Intervalo: " << a << " " << b << "\n A: " << funA;
			double x, fx, fa, fb, interval;
			int k = 0;
		    interval = fabs(b-a);
		    while(k < maxK){
		        x = (a+b)/2;
		        fx = rocketFunction(x, funA);
		        fa = rocketFunction(a, funA);
		        fb = rocketFunction(b, funA);

		        if(fa*fb > 0){
					cout << "\nUm erro ocorreu!";
					cout << "\n" << fa << " " << fb;
					cout << "O intervalo é inválido!";
		            return 0;
		        }
		        if(interval <= error){
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
		    return x;
		}

		double calculateByBissectionNoInterval(double error, int maxK, double funA = 1){
			vector<double> resposta = calculateFunctionInterval(funA);
			cout << "Intervalo: " << resposta[0] << "  " << resposta[1];
			return calculateByBissection(resposta[0], resposta[1], error, maxK, funA);
		}
		
};