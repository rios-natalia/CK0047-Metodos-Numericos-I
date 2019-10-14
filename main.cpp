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
	vector<double> valuesA;
	ConsoleTable bissection(LINED);
	ConsoleTable falsePosition(LINED);
	ConsoleTable newtonRhapson(LINED);
    bissection.setPadding(1);
	falsePosition.setPadding(1);
	newtonRhapson.setPadding(1);
	Methods methods;
	double n, err,input;
	int option;

	cout<< "-------------------------------------------------" <<endl;
	cout<<"Digite o número correspondente ao método desejado:" <<endl;
	cout<< "-------------------------------------------------" <<endl;

	cout<< "-------------------------------" <<endl;
	cout<<"1 - Isolamento sem intervalo" <<endl;
	cout<<"2 - Isolamento com intervalo"<<endl;
	cout<<"3 - Calcular com valores padrão"<<endl;
	cout<< "-------------------------------" <<endl;
	cin>> option;

	if(option == 1) {
		cout<< "---------------------------" <<endl;
		cout<<"Digite o número de foguetes:" <<endl;
		cout<< "---------------------------" <<endl;
		cin>> n;
		cout<< "--------------------------" <<endl;
		cout<<"Digite o a de cada foguete:" <<endl;
		cout<< "--------------------------" <<endl;

		for(int i = 1;i <= n; i++) {
			cin>>input;
			valuesA.push_back(input);
		}

		cout<< "-----------------" <<endl;
		cout<<"Digite a precisão:" <<endl;
		cout<< "-----------------" <<endl;
		cin>> err;

		AnswerFrame* answerFrame = new AnswerFrame(n, valuesA, err);

		answerBissection = answerFrame->getBissection();
		answerFalsePosition = answerFrame->getFalsePosition();
		answerNewtonRhapson = answerFrame->getNewtonRhapson();


		bissection.addColumn("Valor de a");
		bissection.addColumn("Resultado Aproximado");
		bissection.addColumn("Erro Absoluto");

		falsePosition.addColumn("Valor de a");
		falsePosition.addColumn("Resultado Aproximado");
		falsePosition.addColumn("Erro Absoluto");

		newtonRhapson.addColumn("Valor de a");
		newtonRhapson.addColumn("Resultado Aproximado");
		newtonRhapson.addColumn("Erro Absoluto");


		for (int i = 0; i < n; i++){
			auto entry = new ConsoleTableRow(3);
			entry->addEntry(to_string(valuesA[i]), 0);
			entry->addEntry(to_string(answerBissection[i][0]), 1);
			entry->addEntry(to_string(answerBissection[i][1]), 2);
			bissection.addRow(entry);
		}

		for (int i = 0; i < n; i++){
			auto entry = new ConsoleTableRow(3);
			entry->addEntry(to_string(valuesA[i]), 0);
			entry->addEntry(to_string(answerFalsePosition[i][0]), 1);
			entry->addEntry(to_string(answerFalsePosition[i][1]), 2);
			falsePosition.addRow(entry);
		}

		for (int i = 0; i < n; i++){
			auto entry = new ConsoleTableRow(3);
			entry->addEntry(to_string(valuesA[i]), 0);
			entry->addEntry(to_string(answerNewtonRhapson[i][0]), 1);
			entry->addEntry(to_string(answerNewtonRhapson[i][1]), 2);
			newtonRhapson.addRow(entry);
		}

		cout << "--------------------------------------------------" <<endl;
		cout << "OBS: Se Resultado aproximado -1 -> Foguete explode" <<endl;
		cout << "--------------------------------------------------" <<endl;

    	// Print all entries
		cout << "BISSEÇÃO" << endl;
    	bissection.printTable();
		cout << "POSIÇÃO FALSA" << endl;
		falsePosition.printTable();
		cout << "NEWTON-RHAPSON" << endl;
		newtonRhapson.printTable();
		return 0;

	}

	else if(option==2) {

		double a,b,n,guess;

		cout<< "---------------------------" <<endl;
		cout<<"Digite o número de foguetes:" <<endl;
		cout<< "---------------------------" <<endl;
		cin>> n;
		cout<< "--------------------------" <<endl;
		cout<<"Digite o a de cada foguete:" <<endl;
		cout<< "--------------------------" <<endl;

		for(int i = 1;i <= n; i++) {
			cin>>input;
			valuesA.push_back(input);
		}

		cout<< "-----------------" <<endl;
		cout<<"Digite a precisão:" <<endl;
		cout<< "-----------------" <<endl;
		cin>> err;

		cout<< "-----------------------" <<endl;
		cout<<"Digite um chute para x0:" <<endl;
		cout<< "-----------------------" <<endl;
		cin>> guess;
      

		while(guess <=0) {
			cout<<"Chute inválido. Escolha outro valor." <<endl;
			cin>>guess;
		}

		
		AnswerFrame* answerFrame = new AnswerFrame(n,guess,a,b,valuesA, err);

		answerBissection = answerFrame->getBissection();
		answerFalsePosition = answerFrame->getFalsePosition();
		answerNewtonRhapson = answerFrame->getNewtonRhapson();


		bissection.addColumn("Valor de a");
		bissection.addColumn("Resultado Aproximado");
		bissection.addColumn("Erro Absoluto");

		falsePosition.addColumn("Valor de a");
		falsePosition.addColumn("Resultado Aproximado");
		falsePosition.addColumn("Erro Absoluto");

		newtonRhapson.addColumn("Valor de a");
		newtonRhapson.addColumn("Resultado Aproximado");
		newtonRhapson.addColumn("Erro Absoluto");

		for (int i = 0; i < n; i++){
			auto entry = new ConsoleTableRow(3);
			entry->addEntry(to_string(valuesA[i]), 0);
			entry->addEntry(to_string(answerBissection[i][0]), 1);
			entry->addEntry(to_string(answerBissection[i][1]), 2);
			bissection.addRow(entry);
		}

		for (int i = 0; i < n; i++){
			auto entry = new ConsoleTableRow(3);
			entry->addEntry(to_string(valuesA[i]), 0);
			entry->addEntry(to_string(answerFalsePosition[i][0]), 1);
			entry->addEntry(to_string(answerFalsePosition[i][1]), 2);
			falsePosition.addRow(entry);
		}

		for (int i = 0; i < n; i++){
			auto entry = new ConsoleTableRow(3);
			entry->addEntry(to_string(valuesA[i]), 0);
			entry->addEntry(to_string(answerNewtonRhapson[i][0]), 1);
			entry->addEntry(to_string(answerNewtonRhapson[i][1]), 2);
			newtonRhapson.addRow(entry);
		}

		cout << "--------------------------------------------------" <<endl;
		cout << "OBS: Se Resultado aproximado -1 -> Foguete explode" <<endl;
		cout << "--------------------------------------------------" <<endl;

		
    	// Print all entries
		cout << "BISSEÇÃO" << endl;
    	bissection.printTable();
		cout << "POSIÇÃO FALSA" << endl;
		falsePosition.printTable();
		cout << "NEWTON-RHAPSON" << endl;
		newtonRhapson.printTable();
		return 0;

	}
	
	else {
		double n = 1;

		for(int i = 1;i <= n; i++) {
			valuesA.push_back(1);
		}
		double err = 0.00001;

		AnswerFrame* answerFrame = new AnswerFrame(n, valuesA, err);

		answerBissection = answerFrame->getBissection();
		answerFalsePosition = answerFrame->getFalsePosition();
		answerNewtonRhapson = answerFrame->getNewtonRhapson();


		bissection.addColumn("Valor de a");
		bissection.addColumn("Resultado Aproximado");
		bissection.addColumn("Erro Absoluto");

		falsePosition.addColumn("Valor de a");
		falsePosition.addColumn("Resultado Aproximado");
		falsePosition.addColumn("Erro Absoluto");

		newtonRhapson.addColumn("Valor de a");
		newtonRhapson.addColumn("Resultado Aproximado");
		newtonRhapson.addColumn("Erro Absoluto");


		for (int i = 0; i < n; i++){
			auto entry = new ConsoleTableRow(3);
			entry->addEntry(to_string(valuesA[i]), 0);
			entry->addEntry(to_string(answerBissection[i][0]), 1);
			entry->addEntry(to_string(answerBissection[i][1]), 2);
			bissection.addRow(entry);
		}

		for (int i = 0; i < n; i++){
			auto entry = new ConsoleTableRow(3);
			entry->addEntry(to_string(valuesA[i]), 0);
			entry->addEntry(to_string(answerFalsePosition[i][0]), 1);
			entry->addEntry(to_string(answerFalsePosition[i][1]), 2);
			falsePosition.addRow(entry);
		}

		for (int i = 0; i < n; i++){
			auto entry = new ConsoleTableRow(3);
			entry->addEntry(to_string(valuesA[i]), 0);
			entry->addEntry(to_string(answerNewtonRhapson[i][0]), 1);
			entry->addEntry(to_string(answerNewtonRhapson[i][1]), 2);
			newtonRhapson.addRow(entry);
		}

		cout << "--------------------------------------------------" <<endl;
		cout << "OBS: Se Resultado aproximado -1 -> Foguete explode" <<endl;
		cout << "--------------------------------------------------" <<endl;

    	// Print all entries
		cout << "BISSEÇÃO" << endl;
    	bissection.printTable();
		cout << "POSIÇÃO FALSA" << endl;
		falsePosition.printTable();
		cout << "NEWTON-RHAPSON" << endl;
		newtonRhapson.printTable();
		return 0;
	}
	

}