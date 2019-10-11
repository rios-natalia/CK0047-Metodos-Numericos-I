#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>
#include "AnswerFrame.hpp"
#include <unistd.h>
#include "ConsoleTable.hpp"
using namespace std;


int main() {
	vector<vector<double>> answer;
	ConsoleTable ct(BASIC);
    ct.setPadding(1);

    ct.addColumn("Valor de a");
    ct.addColumn(" Bisseção");
    ct.addColumn("Posição Falsa");
    ct.addColumn("Newthon-Rhapson ");

	vector<double> valuesA = {1,2,3,4,5,6,7,8,9,10};
	AnswerFrame answerFrame(10, valuesA, pow(10, -5));
	answer = answerFrame.getRoots();


	for (int i = 0; i < 10; i++){
		auto entry = new ConsoleTableRow(4);
		entry->addEntry(to_string(valuesA[i]), 0);
		entry->addEntry(to_string(answer[i][0]), 1);
		entry->addEntry(to_string(answer[i][1]), 2);
		entry->addEntry(to_string(answer[i][2]), 3);
		ct.addRow(entry);
	}

    // Print all entries
    ct.printTable();
	return 0;
}
