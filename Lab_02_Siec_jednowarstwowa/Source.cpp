#include <iostream>
#include <string>
#include "Perceptron.h"
#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#define numberOfLetters 20
#define pixelsPerLetters 35

using namespace std;
void getPerceptronTestData(int [][pixelsPerLetters],int []);
int main() {

	int numberOfInputs=pixelsPerLetters,numberOfEpochs=0;

	int inputData[numberOfLetters][pixelsPerLetters];
	int expectedResults[numberOfLetters];
	getPerceptronTestData(inputData,expectedResults);
	double learningRate=0.01;
	Perceptron perceptron(numberOfInputs,learningRate);

	//cout << "AND - wyniki PRZED uczeniem" << endl;
	//cout << "Wejscie (0,0) - wynik: " << perceptron.getResult(ZERO_ZERO) << endl;

	int Temp[pixelsPerLetters];
	for(int i=0; i<numberOfLetters; i++)
	{
		//cout<<expectedResults[i]<<" ";
		for(int j=0; j<pixelsPerLetters; j++)
			Temp[i]=inputData[i][j];
		bool done=false;

		while(done==false)
		{
			numberOfEpochs++;
			done=true;
			perceptron.learn(Temp,expectedResults[i]);
			if(perceptron.getResult(Temp)!=expectedResults[i])done=false;
			else cout<<perceptron.getResult(Temp)<<" ";
		}
	}
	cout<<endl;
	for(int i=0; i<numberOfLetters; i++) {
		for(int j=0; j<pixelsPerLetters; j++)
			Temp[i]=inputData[i][j];
		cout << perceptron.getResult(Temp) << " ";
	}

	system("pause");
	return 0;
}
void getPerceptronTestData(int inputData[][pixelsPerLetters],int expectedResults[])
{
	fstream file;
	file.open("data_for_learning.txt");

	if(!file.good()) {
		cout << "--------- I can't open the file with learning data ---------" << endl;
		system("PAUSE");
		exit(0);
	}

	//wczytuj z pliku dopóki s¹ dane
	while(!file.eof())
		for(int i = 0; i < numberOfLetters; i++) { // i oznacza indeks litery
			for(int j = 0; j < pixelsPerLetters; j++) // j oznacza ilosc bitow na dan¹ litere
				file >> inputData[i][j]; //wczytywanie do tablicy z wejsciami

			file >> expectedResults[i]; //wczytanie z pliku czy dana litera jest duza (1) lub mala (0)
		}

	file.close();
};