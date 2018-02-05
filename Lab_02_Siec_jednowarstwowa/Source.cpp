
#include "Perceptron.h"
#include "Adaline.h"
#include "DeltaRule.h"
#pragma once

using namespace std;
void getTestData(double[][pixelsPerLetters],int[]);
void PerceptronMain(Perceptron);
void AdalineMain(Adaline);
void DeltaRuleMain(DeltaRule);
int main() {

	int numberOfInputs=pixelsPerLetters;

	double learningRate=0.75,EMax=0.01;
	Perceptron perceptron(numberOfInputs,learningRate);
	PerceptronMain(perceptron);
	cout<<endl;
	//Adaline adaline(numberOfInputs,learningRate,EMax);
	//AdalineMain(adaline);
	cout<<endl;
	//DeltaRule deltarule(numberOfInputs,learningRate,EMax);
	//DeltaRuleMain(deltarule);

	system("pause");
	return 0;
}



void getTestData(double inputData[][pixelsPerLetters],int expectedResults[])
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
void PerceptronMain(Perceptron perceptron)
{

	char Letters[20] ={'A','B','C','D','E','F','G','H','I','J','a','b','c','d','e','f','g','h','i','j'};
	double inputData[numberOfLetters][pixelsPerLetters];
	int expectedResults[numberOfLetters];
	getTestData(inputData,expectedResults);
	int numberOfEpochs=0;
	cout << "Perceptron - wyniki przed uczeniem: " << endl;

	double Temp[pixelsPerLetters];
	for(int i=0; i<numberOfLetters; i++)
	{
		for(int j=0; j<pixelsPerLetters; j++)
		{
			Temp[j]=inputData[i][j];
		}
		cout<<Letters[i]<<" - ";
		for(int j=0; j<pixelsPerLetters; j++)
			cout<<Temp[j]<<" ";
		cout<<" "<<perceptron.getResult(Temp)<<" "<<endl;

		while(perceptron.getResult(Temp)!=expectedResults[i])
		{
			numberOfEpochs++;
			perceptron.learn(Temp,expectedResults[i]);
		}
	}
	cout<<endl;
	cout << "Perceptron - wyniki po uczeniu: " << endl;
	cout<<"Liczba epok: "<<numberOfEpochs<<endl;
	for(int i=0; i<numberOfLetters; i++) {
		cout<<Letters[i]<<" - ";
		for(int j=0; j<pixelsPerLetters; j++)
		{
			Temp[j]=inputData[i][j];
			cout<<Temp[j]<<" ";
		}
		cout<<" "<< perceptron.getResult(Temp) << " "<< endl;
	}
};
void AdalineMain(Adaline adaline)
{

	char Letters[20] ={'A','B','C','D','E','F','G','H','I','J','a','b','c','d','e','f','g','h','i','j'};
	double inputData[numberOfLetters][pixelsPerLetters];
	int expectedResults[numberOfLetters];
	getTestData(inputData,expectedResults);
	int numberOfEpochs=0;
	cout << "Adaline - wyniki przed uczeniem: " << endl;

	double Temp[pixelsPerLetters];
	for(int i=0; i<numberOfLetters; i++) {
		cout<<Letters[i]<<" - ";
		for(int j=0; j<pixelsPerLetters; j++)
		{
			Temp[j]=inputData[i][j];
			cout<<Temp[j]<<" ";
		}
		cout<<" "<< adaline.getResult(Temp) << " "<< endl;
	}
	int epoch=0;
	do
	{
		for(int i=0; i<numberOfLetters; i++)
		{
			for(int j=0; j<pixelsPerLetters; j++)
			{
				Temp[j]=inputData[i][j];
			}
			adaline.learn(Temp,expectedResults[i]);
			adaline.error=adaline.error/2;
		}
		epoch++;
	}while(adaline.EMax<adaline.error);
	cout <<endl<< "Adaline - wyniki po uczeniu: " << endl;
	cout<<"Liczba epok: "<<epoch<<endl;
	for(int i=0; i<numberOfLetters; i++) {
		cout<<Letters[i]<<" - ";
		for(int j=0; j<pixelsPerLetters; j++)
		{
			Temp[j]=inputData[i][j];
			cout<<Temp[j]<<" ";
		}
		cout<<" "<< adaline.getResult(Temp) << " "<< endl;
	}
};
void DeltaRuleMain(DeltaRule deltarule)
{
	char Letters[20] ={'A','B','C','D','E','F','G','H','I','J','a','b','c','d','e','f','g','h','i','j'};
	double inputData[numberOfLetters][pixelsPerLetters];
	int expectedResults[numberOfLetters];
	getTestData(inputData,expectedResults);
	int numberOfEpochs=0;
	cout << "Delta Rule - wyniki przed uczeniem: " << endl;

	double Temp[pixelsPerLetters];
	for(int i=0; i<numberOfLetters; i++) {
		cout<<Letters[i]<<" - ";
		for(int j=0; j<pixelsPerLetters; j++)
		{
			Temp[j]=inputData[i][j];
			cout<<Temp[j]<<" ";
		}
		cout<<" "<< deltarule.getResult(Temp) << " "<< endl;
	}
	int epoch=0;
	do
	{
		for(int i=0; i<numberOfLetters; i++)
		{
			for(int j=0; j<pixelsPerLetters; j++)
			{
				Temp[j]=inputData[i][j];
			}
			deltarule.learn(Temp,expectedResults[i]);
			deltarule.error=deltarule.error/2;
		}
		epoch++;
	} while(deltarule.EMax<deltarule.error);
	cout <<endl<< "Delta Rule - wyniki po uczeniu: " << endl;
	cout<<"Liczba epok: "<<epoch<<endl;
	for(int i=0; i<numberOfLetters; i++) 
	{
		cout<<Letters[i]<<" - ";
		for(int j=0; j<pixelsPerLetters; j++)
		{
			Temp[j]=inputData[i][j];
			cout<<Temp[j]<<" ";
		}
		cout<<" "<< deltarule.getResult(Temp) << " "<< endl;
	}
};