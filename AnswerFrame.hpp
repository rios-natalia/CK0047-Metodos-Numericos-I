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
    Answer bissection;
    Answer falsePosition;
    Answer newtonRhapson;
    vector<double> rootsMethods;
    Methods methods;
    bissection = methods.calculateByBissectionNoInterval(pow(10, -5), 1000, 1);
    falsePosition = methods.calculateByFalsePositionNoInterval(pow(10, -5), pow(10, -5), 1000, 1);
    newtonRhapson = methods.calculateByNewtonRhapsonIntervalBasedGuess(pow(10, -5), pow(10, -5), 1000, 1);
    rootsMethods = {bissection.getResult(), falsePosition.getResult(), newtonRhapson.getResult()};
    this->roots.push_back(rootsMethods);
}

AnswerFrame:: AnswerFrame(int number, vector<double> valuesA, double precision) {
    Answer bissection;
    Answer falsePosition;
    Answer newtonRhapson;
    vector<double> rootsMethods;
    for (int i = 0; i < number; i++){
        Methods methods;
        bissection = methods.calculateByBissectionNoInterval(precision, 1000, valuesA[i]);
        falsePosition = methods.calculateByFalsePositionNoInterval(precision, precision,  1000, valuesA[i]);
        newtonRhapson = methods.calculateByNewtonRhapsonIntervalBasedGuess(precision, precision, 1000, valuesA[i]);
        rootsMethods = {bissection.getResult(), falsePosition.getResult(), newtonRhapson.getResult()};
        this->roots.push_back(rootsMethods);
    }
}

AnswerFrame::~ AnswerFrame() {
    free(&roots);
}

 vector<vector<double>> AnswerFrame:: getRoots() {
     return this->roots;
 }