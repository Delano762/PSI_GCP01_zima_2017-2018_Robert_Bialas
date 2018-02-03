#include <iostream>
#include <ctime>
#include "Perceptron.h"


//ucz sie, czyli:
void Perceptron::learn(const double inputs[],int expectedResult) {
	int result = getResult(inputs);//otrzymaj wyniki, czyli zsumuj kazde wi*xi i przekaz sumę funkcji aktywacyjnej
	if(result == expectedResult)//Jesli wynik sie zgadza z pozadanym...
		return;//Zatrzymujemy uczenie
	changeWeights(result,expectedResult,inputs);//W przeciwnym wypadku zmieniamy wagi
}

int Perceptron::getResult(const double inputs[])
{
	double sum=0;
	for(int i=0; i<this->numberOfInputs; i++)
		sum+=this->weights[i]*inputs[i];//suma wejść przemnożonych przez wagi
										//if(sum>1) return 1;//FUNKCJA AKTYWACYJNA
										//else return 0;
	return(sum>1) ? 1:0;
}

void Perceptron::changeWeights(int actualResult,int desiredResult,const double inputs[])
{
	for(int i=0; i<this->numberOfInputs; i++)
		this->weights[i]+=this->learningRate*(desiredResult-actualResult)*inputs[i];//współczynnik uczenia*błąd lokalny*xi
}//deltawij = xj(di-yi) <- Osowski, (2.4) str. 19; Działanie uczenia jest przyśpieszone poprzez pomnożenie deltawij przez współczynnik uczenia

Perceptron::Perceptron(unsigned numOfInputs,double trainingRate) {
	srand(time(NULL));
	this->learningRate = trainingRate;

	this->numberOfInputs = numOfInputs;
	if(this->numberOfInputs <= 0)
		this->numberOfInputs = 1;

	this->weights = new double[numberOfInputs];//tworzymy tablice wag, zalezna od ilosci wejsc
	for(int i = 0; i < this->numberOfInputs; i++)
		this->weights[i] = getRandomDouble();//Wagi wi są przypadkowymi liczbami zmiennoprzecinkowymi
}

double Perceptron::getRandomDouble()
{
	return ((double)rand()/(double)RAND_MAX);
}

Perceptron::Perceptron() {//Konstruktor domyślny
	srand(time(NULL));
	this->learningRate = 0.01;

	this->numberOfInputs = numberOfLetters;
	if(this->numberOfInputs <= 0)
		this->numberOfInputs = 1;

	this->weights = new double[numberOfInputs];//tworzymy tablice wag, zalezna od ilosci wejsc
	for(int i = 0; i < this->numberOfInputs; i++)
		this->weights[i] = getRandomDouble();//Wagi wi są przypadkowymi liczbami zmiennoprzecinkowymi
}

void Perceptron::getTestData(double inputData[][pixelsPerLetters],int expectedResults[])
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