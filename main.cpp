#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>
#include "AnswerFrame.hpp"
#include <unistd.h>
#include "ConsoleTable.hpp"
using namespace std;


int main() {
	vector<vector<double>> answerBissection;
	vector<vector<double>> answerFalsePosition;
	vector<vector<double>> answerNewtonRhapson;
	ConsoleTable bissection(LINED);
	ConsoleTable falsePosition(LINED);
	ConsoleTable newtonRhapson(LINED);
    bissection.setPadding(1);
	falsePosition.setPadding(1);
	newtonRhapson.setPadding(1);

	bissection.addColumn("Valor de a");
	bissection.addColumn("Resultado Aproximado");
	bissection.addColumn("Erro Absoluto");

	falsePosition.addColumn("Valor de a");
	falsePosition.addColumn("Resultado Aproximado");
	falsePosition.addColumn("Erro Absoluto");

	newtonRhapson.addColumn("Valor de a");
	newtonRhapson.addColumn("Resultado Aproximado");
	newtonRhapson.addColumn("Erro Absoluto");


	vector<double> valuesA = {1.5,2.2,3.3,4.7,5.09,6.003,7.81,8.3,9.44,10.11};
	AnswerFrame answerFrame(10, valuesA, pow(10, -5));
	
	answerBissection = answerFrame.getBissection();
	answerFalsePosition = answerFrame.getFalsePosition();
	answerNewtonRhapson = answerFrame.getNewtonRhapson();


	for (int i = 0; i < 10; i++){
		auto entry = new ConsoleTableRow(3);
		entry->addEntry(to_string(valuesA[i]), 0);
		entry->addEntry(to_string(answerBissection[i][0]), 1);
		entry->addEntry(to_string(answerBissection[i][1]), 2);
		bissection.addRow(entry);
	}

	for (int i = 0; i < 10; i++){
		auto entry = new ConsoleTableRow(3);
		entry->addEntry(to_string(valuesA[i]), 0);
		entry->addEntry(to_string(answerFalsePosition[i][0]), 1);
		entry->addEntry(to_string(answerFalsePosition[i][1]), 2);
		falsePosition.addRow(entry);
	}

	for (int i = 0; i < 10; i++){
		auto entry = new ConsoleTableRow(3);
		entry->addEntry(to_string(valuesA[i]), 0);
		entry->addEntry(to_string(answerNewtonRhapson[i][0]), 1);
		entry->addEntry(to_string(answerNewtonRhapson[i][1]), 2);
		newtonRhapson.addRow(entry);
	}

    // Print all entries
	cout << "BISSEÇÃO" << endl;
    bissection.printTable();
	cout << "POSIÇÃO FALSA" << endl;
	falsePosition.printTable();
	cout << "NEWTON-RHAPSON" << endl;
	newtonRhapson.printTable();
	return 0;
}
