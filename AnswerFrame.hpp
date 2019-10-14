#include <iostream>
#include <vector>
#include "methods.hpp"
using std::vector;
using namespace std;

class  AnswerFrame
{
private:
    vector<vector<double>> answerBissection;
    vector<vector<double>> answerFalsePosition;
    vector<vector<double>> answerNewtonRhapson;
public:
    AnswerFrame();
    AnswerFrame(int number, vector<double> valuesA, double precision1, double precision2);
    AnswerFrame(int number, double lim_inf, double lim_sup, vector<double> valuesA, double precision1, double precision2);
    AnswerFrame(int number, double x0, double lim_inf, double lim_sup, vector<double> valuesA, double precision1, double precision2);
    vector<vector<double>> getBissection();
    vector<vector<double>> getFalsePosition();
    vector<vector<double>> getNewtonRhapson();
    ~ AnswerFrame();
};

AnswerFrame:: AnswerFrame() {
    Answer bissection;
    Answer falsePosition;
    Answer newtonRhapson;
    vector<double> valuesBissection;
    vector<double> valuesFalsePosition;
    vector<double> valuesNewtonRhapson;
    Methods methods;
    bissection = methods.calculateByBissectionNoInterval(pow(10, -5), 1000, 1);
    falsePosition = methods.calculateByFalsePositionNoInterval(pow(10, -5), pow(10, -5), 1000, 1);
    newtonRhapson = methods.calculateByNewtonRhapsonIntervalBasedGuess(pow(10, -5), pow(10, -5), 1000, 1);
    valuesBissection = {bissection.getResult(), bissection.getAbsoluteError()};
    valuesFalsePosition = {falsePosition.getResult(), falsePosition.getAbsoluteError()};
    valuesNewtonRhapson = {newtonRhapson.getResult(), newtonRhapson.getAbsoluteError()};
    this->answerBissection.push_back(valuesBissection);
    this->answerFalsePosition.push_back(valuesFalsePosition);
    this->answerNewtonRhapson.push_back(valuesNewtonRhapson);
}
	
AnswerFrame:: AnswerFrame(int number, double lim_inf, double lim_sup, vector<double> valuesA, double precision1,double precision2) {
	Methods methods;
    Answer bissection;
    Answer falsePosition;
    Answer newtonRhapson;
    vector<double> valuesBissection;
    vector<double> valuesFalsePosition;
    vector<double> valuesNewtonRhapson;
    for (int i = 0; i < number; i++){
        bissection = methods.calculateByBissection(lim_inf,lim_sup,precision1,1000,valuesA[i]);
        falsePosition = methods.calculateByFalsePosition(lim_inf, lim_sup,precision1, precision2, 1000, valuesA[i]);
        newtonRhapson = methods.calculateByNewtonRhapsonIntervalBasedGuess(precision1, precision2, 1000, valuesA[i]);
        valuesBissection = {bissection.getResult(), bissection.getAbsoluteError()};
        valuesFalsePosition = {falsePosition.getResult(), falsePosition.getAbsoluteError()};
        valuesNewtonRhapson = {newtonRhapson.getResult(), newtonRhapson.getAbsoluteError()};
        this->answerBissection.push_back(valuesBissection);
        this->answerFalsePosition.push_back(valuesFalsePosition);
        this->answerNewtonRhapson.push_back(valuesNewtonRhapson);
    }
}

AnswerFrame:: AnswerFrame(int number, double x0, double lim_inf, double lim_sup, vector<double> valuesA, double precision1, double precision2) {
    Methods methods;
    Answer bissection;
    Answer falsePosition;
    Answer newtonRhapson;
    vector<double> valuesBissection;
    vector<double> valuesFalsePosition;
    vector<double> valuesNewtonRhapson;
    for (int i = 0; i < number; i++){
        bissection = methods.calculateByBissection(lim_inf,lim_sup,precision1,1000,valuesA[i]);
        falsePosition = methods.calculateByFalsePosition(lim_inf, lim_sup,precision1, precision2, 1000, valuesA[i]);
        newtonRhapson = methods.calculateByNewtonRhapson(x0,precision1, precision2, 1000, valuesA[i]);
        valuesBissection = {bissection.getResult(), bissection.getAbsoluteError()};
        valuesFalsePosition = {falsePosition.getResult(), falsePosition.getAbsoluteError()};
        valuesNewtonRhapson = {newtonRhapson.getResult(), newtonRhapson.getAbsoluteError()};
        this->answerBissection.push_back(valuesBissection);
        this->answerFalsePosition.push_back(valuesFalsePosition);
        this->answerNewtonRhapson.push_back(valuesNewtonRhapson);
    }
}


AnswerFrame:: AnswerFrame(int number, vector<double> valuesA, double precision1, double precision2) {
    Methods methods;
    Answer bissection;
    Answer falsePosition;
    Answer newtonRhapson;
    Answer newtonRhapson2;
    vector<double> valuesBissection;
    vector<double> valuesFalsePosition;
    vector<double> valuesNewtonRhapson;
    for (int i = 0; i < number; i++){
        bissection = methods.calculateByBissectionNoInterval(precision1, 1000, valuesA[i]);
        falsePosition = methods.calculateByFalsePositionNoInterval(precision1, precision2, 1000, valuesA[i]);
        newtonRhapson = methods.calculateByNewtonRhapsonIntervalBasedGuess(precision1, precision2, 1000, valuesA[i]);
        valuesBissection = {bissection.getResult(), bissection.getAbsoluteError()};
        valuesFalsePosition = {falsePosition.getResult(), falsePosition.getAbsoluteError()};
        valuesNewtonRhapson = {newtonRhapson.getResult(), newtonRhapson.getAbsoluteError()};
        this->answerBissection.push_back(valuesBissection);
        this->answerFalsePosition.push_back(valuesFalsePosition);
        this->answerNewtonRhapson.push_back(valuesNewtonRhapson);
    }
}


vector<vector<double>> AnswerFrame:: getBissection() {
    return this->answerBissection;
}

vector<vector<double>> AnswerFrame:: getFalsePosition() {
    return this->answerFalsePosition;
}

vector<vector<double>> AnswerFrame:: getNewtonRhapson() {
    return this->answerNewtonRhapson;
}