#include <math.h>
using namespace std;
class Methods{
	private:
		double rocketFunction(double d, double a=1){
			return (a*d) - ( d * log(d) );				
		};
		double rocketFunctionDerivative(double d, double a=1){
			return -1*log(d) + a -1;
		};
	public:
		double calculateFunction(double d, double a=1){
			return rocketFunction(d,a);
		};
		double calculateFunctionDerivative(double d, double a=1){
			return rocketFunctionDerivative(d, a);
		};
};