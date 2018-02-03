
#include "Perceptron.h"
#include "Adaline.h"
#pragma once

using namespace std;
void getPerceptronTestData(double [][pixelsPerLetters],int []);
void PerceptronNonsense(Perceptron);
void AdalineNonsense(Adaline);
int main() {

	int numberOfInputs=pixelsPerLetters;

	double learningRate=0.01;
	Perceptron perceptron(numberOfInputs,learningRate);
	PerceptronNonsense(perceptron);
	
	Adaline adaline(numberOfInputs,learningRate);
	AdalineNonsense(adaline);


	system("pause");
	return 0;
}



void getPerceptronTestData(double inputData[][pixelsPerLetters],int expectedResults[])
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
void PerceptronNonsense(Perceptron perceptron)
{

	char Letters[20] ={'A','B','C','D','E','F','G','H','I','J','a','b','c','d','e','f','g','h','i','j'};
	double inputData[numberOfLetters][pixelsPerLetters];
	int expectedResults[numberOfLetters];
	getPerceptronTestData(inputData,expectedResults);
	int numberOfEpochs=0;
	cout << "Perceptron - wyniki przed uczeniem: " << endl;

	double Temp[pixelsPerLetters];
	for(int i=0; i<numberOfLetters; i++)
	{
		for(int j=0; j<pixelsPerLetters; j++)
		{
			Temp[j]=inputData[i][j];
			//cout<<Temp[i]<<" ";
		}
		//cout<<endl;
		cout<<Letters[i]<<" - ";
		for(int j=0; j<pixelsPerLetters; j++)
			cout<<Temp[j]<<" ";
		cout<<" "<<perceptron.getResult(Temp)<<" "<<endl;

		bool done=false;

		while(done==false)
		{
			numberOfEpochs++;
			done=true;
			perceptron.learn(Temp,expectedResults[i]);
			if(perceptron.getResult(Temp)!=expectedResults[i])done=false;
			//else cout<<perceptron.getResult(Temp)<<" ";
			/*else
			{
			for(int j=0; j<pixelsPerLetters; j++)
			cout<<Temp[j]<<" ";
			cout<<" "<<perceptron.getResult(Temp)<<" "<<endl;
			}*/

		}
		//cout<<endl;
	}
	cout<<endl;
	cout << "Perceptron - wyniki po uczeniu: " << endl;
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
void AdalineNonsense(Adaline adaline)
{

	char Letters[20] ={'A','B','C','D','E','F','G','H','I','J','a','b','c','d','e','f','g','h','i','j'};
	double inputData[numberOfLetters][pixelsPerLetters];
	int expectedResults[numberOfLetters];
	getPerceptronTestData(inputData,expectedResults);
	int numberOfEpochs=0;
	cout << "Adaline - wyniki przed uczeniem: " << endl;

	double Temp[pixelsPerLetters];
	for(int i=0; i<numberOfLetters; i++)
	{
		for(int j=0; j<pixelsPerLetters; j++)
		{
			Temp[j]=inputData[i][j];
			//cout<<Temp[i]<<" ";
		}
		//cout<<endl;
		cout<<Letters[i]<<" - ";
		for(int j=0; j<pixelsPerLetters; j++)
			cout<<Temp[j]<<" ";
		cout<<" "<<adaline.getResult(Temp)<<" "<<endl;

		bool done=false;

		while(done==false)
		{
			numberOfEpochs++;
			done=true;
			adaline.learn(Temp,expectedResults[i]);
			if(adaline.getResult(Temp)!=expectedResults[i])done=false;
			//else cout<<perceptron.getResult(Temp)<<" ";
			/*else
			{
			for(int j=0; j<pixelsPerLetters; j++)
			cout<<Temp[j]<<" ";
			cout<<" "<<perceptron.getResult(Temp)<<" "<<endl;
			}*/

		}
		//cout<<endl;
	}
	cout<<endl;
	cout << "Adaline - wyniki po uczeniu: " << endl;
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