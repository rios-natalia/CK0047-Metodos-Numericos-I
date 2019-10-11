#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>
#include "AnswerFrame.hpp"
#include <unistd.h>
#include "ConsoleTable.hpp"
using namespace std;


int main() {
	AnswerFrame answerFrame(10, {0,1,2,3,4,5,6,7,8,9},pow(10, -5));
	vector<vector<double>> answer;
	ConsoleTable ct(BASIC);
    ct.setPadding(1);

    ct.addColumn("Valor de a");
    ct.addColumn(" Bisseção");
    ct.addColumn("Posição Falsa");
    ct.addColumn("Newthon-Rhapson ");

	answer = answerFrame.getRoots();

	for (int i = 0; i < 10; i++){
		auto entry = new ConsoleTableRow(4);
		entry->addEntry(to_string(i+1), 0);
		entry->addEntry(to_string(answer[i][0]), 1);
		entry->addEntry(to_string(answer[i][1]), 2);
		entry->addEntry("Não tenho", 3);
		ct.addRow(entry);
	}

    // Print all entries
    ct.printTable();
	return 0;
}
