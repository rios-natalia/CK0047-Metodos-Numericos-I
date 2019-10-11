#include <iostream>
#include <vector>
#include "methods.hpp"
using std::vector;
using namespace std;

class  AnswerFrame
{
private:
    vector<vector<double>> roots;
public:
    AnswerFrame();
    AnswerFrame(int number, vector<double> valuesA, double precision);
    vector<vector<double>> getRoots();
    ~ AnswerFrame();
};

AnswerFrame:: AnswerFrame() {
    double rootBissection;
    double rootFalsePosition;
    double rootNewtonRhapson;
    vector<double> rootsMethods;
    Methods methods;
    rootBissection = methods.calculateByBissectionNoInterval(pow(10, -5), 1000, 1);
    rootFalsePosition = methods.calculateByFalsePositionNoInterval(pow(10, -5), 1000, 1);
    rootsMethods = {rootBissection, rootFalsePosition};
    this->roots.push_back(rootsMethods);
}

AnswerFrame:: AnswerFrame(int number, vector<double> valuesA, double precision) {
    double rootBissection;
    double rootFalsePosition;
    double rootNewtonRhapson;
    vector<double> rootsMethods;
    for (int i = 0; i < number; i++){
        Methods methods;
        rootBissection = methods.calculateByBissectionNoInterval(precision, 1000, valuesA[i]);
        rootFalsePosition = methods.calculateByFalsePositionNoInterval(precision, 1000, valuesA[i]);
        rootsMethods = {rootBissection, rootFalsePosition};
        this->roots.push_back(rootsMethods);
    }
}

AnswerFrame::~ AnswerFrame() {
    free(&roots);
}

 vector<vector<double>> AnswerFrame:: getRoots() {
     return this->roots;
 }