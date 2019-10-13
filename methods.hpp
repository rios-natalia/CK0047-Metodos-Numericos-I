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
			double x = 0, fx, fa, fb, interval;
			int k = 0;
			double previousX;
		    interval = fabs(b-a);
		    while(k < maxK){
				previousX = x;
		        x = (a+b)/2;
		        fx = rocketFunction(x, funA);
		        fa = rocketFunction(a, funA);
		        fb = rocketFunction(b, funA);
				
		        if(isnan(fx) > 0 || fa*fb > 0){
					return Answer("O intervalo é inválido!");
		        }

		        if(interval <= error){
					end = clock(); 

					return Answer(x, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)), abs(previousX - x));
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
			return Answer(x, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)), abs(previousX - x));
		}

		Answer calculateByBissectionNoInterval(double error, int maxK, double funA = 1){
			vector<double> resposta = calculateFunctionInterval(funA);
			return calculateByBissection(resposta[0], resposta[1], error, maxK, funA);
		}

		// Padrão: a= 1, isolamento = (2, 3) e ε= 10^-5. 
		//Usando maxK = 100 por padrão, mas pode ser especificado
		Answer calculateByBissectionDefault(int maxK = 100){
			return calculateByBissection(2, 3, 1e-5, maxK, 1);
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
				return Answer(x0, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)), 0);
			}
			
			
			while(k < maxK) {
				
				double x1 = x0 - rocketFunction(x0, funA)/rocketFunctionDerivative(x0, funA);
				
				if(isnan(x1) || isnan(fx) || rocketFunctionDerivative(x0, funA) == 0){
					return Answer("O chute dado é inválido!");
				}

			    if(abs(rocketFunction(x1, funA)) < error1 || abs(x1-x0) < error2) {
					end = clock(); 
					return Answer(x1, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)), abs(x1-x0));
			    }
			    x0 = x1;
			    k++;
			  }
			end = clock(); 
			return Answer(x0, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)));
		}

		// Nossa derivada precisa ser diferente de zero sempre, logo, se:
		// -ln d + a - 1 != 0 então
		// ln d != a - 1
		// Portanto, é seguro chutar ln d = a
		// Logo, nosso chute é e^a
		// Infelizmente, esse chute ACERTA,então não vamos usá-lo
		//                       :(
		Answer calculateByNewtonRhapsonEulerBasedGuess(double error1, double error2, int maxK, double funA = 1){
			return calculateByNewtonRhapson(exp(funA) , error1, error2, maxK, funA);
		}

		// Chute burro
		// Vê um intervalo ok com o nosso funA e chuta no meio dele
		Answer calculateByNewtonRhapsonIntervalBasedGuess(double error1, double error2, int maxK, double funA = 1){
			vector<double> resposta = calculateFunctionInterval(funA);
			return calculateByNewtonRhapson( (resposta[0]+resposta[1])/2 , error1, error2, maxK, funA);
		}

		// Padrão: a= 1, isolamento = (2, 3) e ε= 10^-5. 
		// Usando maxK = 100 por padrão, mas pode ser especificado
		// O chute é a metade do intervalo padrão, logo, 1.5
		Answer calculateByNewtonRhapsonDefault(int maxK = 100){
			return calculateByNewtonRhapson(1.5, 1e-5, 1e-5, maxK, 1);
		}

		Answer calculateByFalsePositionNoInterval(double error1, double error2, int maxK, double funA = 1){
			vector <double> resposta = calculateFunctionInterval(funA);
			return calculateByFalsePosition(resposta[0], resposta[1], error1, error2, maxK, funA);
		}

		Answer calculateByFalsePosition(double a, double b, double error1, double error2, int maxK, double funA =1){
			clock_t start, end; start = clock(); 
			double x = 0, fx, fa, fb, interval;
			double previousX;
			int k = 0;
			interval = fabs(b-a);
			
			while(k < maxK){
				fa = rocketFunction(a,funA);
				fb = rocketFunction(b,funA);
				previousX = x;
				x = (a*fb - b*fa)/(fb-fa);
				fx = rocketFunction(x,funA);
				// fabs => retorna o módulo do double passado

				if(fa*fb > 0 || isnan(fx)){
					end = clock(); 
					return Answer("O intervalo é inválido!");
				}
				
				if(fabs(fx) < error2 || k > maxK){
					end = clock(); 
					return Answer(x, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)), abs(x-previousX));
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
					return Answer(x, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)), abs(x-previousX));
				}
				k ++;
			}

			
			end = clock(); 
			return Answer(x, k, 1000*(double(end - start) / double(CLOCKS_PER_SEC)), abs(x-previousX));
			
		}

		// Padrão: a = 1, isolamento = (2, 3) e ε= 10^-5. 
		// Usando maxK = 100 por padrão, mas pode ser especificado
		Answer calculateByFalsePositionDefault(int maxK = 100){
			return calculateByFalsePosition(2, 3, 1e-5, 1e-5, maxK, 1);
		}
};