#include <math.h>
#include <iostream>
#include <vector>
#include <time.h>
#include "Answer.hpp"
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
		Answer calculateByBissection(double a, double b, double error, int maxK, double funA = 1){
			clock_t start, end; start = clock(); 
			double x, fx, fa, fb, interval;
			int k = 0;
		    interval = fabs(b-a);
		    while(k < maxK){
		        x = (a+b)/2;
		        fx = rocketFunction(x, funA);
		        fa = rocketFunction(a, funA);
		        fb = rocketFunction(b, funA);
				
		        if(isnan(fx) > 0 || fa*fb > 0){
					return Answer("O intervalo é inválido!");
		        }

		        if(interval <= error){
					end = clock(); 
					return Answer(x, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)));
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
			end = clock(); 
			return Answer(x, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)));
		}

		Answer calculateByBissectionNoInterval(double error, int maxK, double funA = 1){
			vector<double> resposta = calculateFunctionInterval(funA);
			return calculateByBissection(resposta[0], resposta[1], error, maxK, funA);
		}
		
		// OBSERVAÇÂO: O chute desse método jamais poderá <= 0!
		Answer calculateByNewtonRhapson(double x0, double error1, double error2, int maxK, double funA = 1){
			clock_t start, end; start = clock(); 

			if(x0 <= 0){
				end = clock(); 
				return Answer("O chute dado é inválido!");
			}

			double fx = rocketFunction(x0, funA);
			int k = 0;
			if(abs(fx) < error1){
				end = clock(); 
				return Answer(x0, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)));
			}
			
			
			while(k < maxK) {
				if(rocketFunctionDerivative(x0, funA) == 0){
					return Answer("O chute dado é inválido!");
				}
				double x1 = x0 - rocketFunction(x0, funA)/rocketFunctionDerivative(x0, funA);
				
			    if(abs(rocketFunction(x1, funA)) < error1 || abs(x1-x0) < error2) {
					end = clock(); 
					return Answer(x1, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)));
			    }
			    x0 = x1;
			    k++;
			  }
			end = clock(); 
			return Answer(x0, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)));
		}

		Answer calculateByFalsePositionNoInterval(double error1, double error2, int maxK, double funA = 1){
			vector <double> resposta = calculateFunctionInterval(funA);
			return calculateByFalsePosition(resposta[0], resposta[1], error1, error2, maxK, funA);
		}

		Answer calculateByFalsePosition(double a, double b, double error1, double error2, int maxK, double funA =1){
			clock_t start, end; start = clock(); 
			double x, fx, fa, fb, interval;
			int k = 0;
			interval = fabs(b-a);
			
			while(k < maxK){
				fa = rocketFunction(a,funA);
				fb = rocketFunction(b,funA);

				x = (a*fb - b*fa)/(fb-fa);
				fx = rocketFunction(x,funA);
				// fabs => retorna o módulo do double passado

				if(fa*fb > 0 || isnan(fx)){
					end = clock(); 
					return Answer("O intervalo é inválido!");
				}
				
				if(fabs(fx) < error2 || k > maxK){
					end = clock(); 
					return Answer(x, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)));
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
					return Answer(x, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)));
				}
				k ++;
			}

			
			end = clock(); 
			return Answer(x, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)));
			
		}
};