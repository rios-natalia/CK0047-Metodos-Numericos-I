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

		// TÁ UMA BOSTA TEM QUE REFAZER ESSA MERDA 
		vector<double> getInterval(double a=1){
			double aI = 0.000001;
			double bI = 10;
			cout << "\n\nf(aI): "<< rocketFunction(aI, a) << "\nf(bI): "<<rocketFunction(bI, a);
			while(rocketFunction(aI, a)*rocketFunction(bI, a) > 0){
				if(aI == 0.000001){
					aI += 9.999999;	
				}
				else{
					aI += 10;
				}
				bI += 10;
			}
			vector <double> result;
			result.push_back(aI);
			result.push_back(bI);
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

		double bissection(double a, double b, double error, int maxK){
			double x, fx, fa, fb, interval;
			int k = 0;
		    interval = fabs(b-a);
		    while(k < maxK){
		        x = (a+b)/2;
		        fx = rocketFunction(x);
		        fa = rocketFunction(a);
		        fb = rocketFunction(b);

		        if(fa*fb > 0){
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
};