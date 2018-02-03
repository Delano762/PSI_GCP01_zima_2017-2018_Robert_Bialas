#include <iostream>
#include <ctime>
#include "Adaline.h"


//ucz sie, czyli:
void Adaline::learn(const double inputs[],int expectedResult) {

	//bool acceptableError = false; //zmienna, stwierdzajaca czy blad jest mozliwy do zaakceptowania
	int result = getResult(inputs);//otrzymaj wyniki, czyli zsumuj kazde wi*xi i przekaz sumę funkcji aktywacyjnej
	error=0.5*pow((expectedResult-sum),2);
	if(result == expectedResult)//Jesli wynik sie zgadza z pozadanym...
		return;//Zatrzymujemy uczenie

	changeWeights(sum,expectedResult,inputs);//W przeciwnym wypadku zmieniamy wagi
}

int Adaline::getResult(const double inputs[])
{
	double Sum=0;
	for(int i=0; i<this->numberOfInputs; i++)
		Sum+=this->weights[i]*inputs[i];//suma wejść przemnożonych przez wagi
										//if(sum>1) return 1;//FUNKCJA AKTYWACYJNA
										//else return 0;
	this->sum=Sum;
	return(Sum>0.5) ? 1:0;
}

void Adaline::changeWeights(double actualResult,int desiredResult,const double inputs[])
{
	for(int i=0; i<this->numberOfInputs; i++)
		this->weights[i]+=this->learningRate*(desiredResult-actualResult)*inputs[i];//współczynnik uczenia*błąd lokalny*xi
}//deltawij = xj(di-yi) <- Osowski, (2.4) str. 19; Działanie uczenia jest przyśpieszone poprzez pomnożenie deltawij przez współczynnik uczenia

Adaline::Adaline(unsigned numOfInputs,double trainingRate) {
	srand(time(NULL));
	this->learningRate = trainingRate;
	this->learningRate = 0.01;
	this->EMax=0.0001;

	this->numberOfInputs = numOfInputs;
	if(this->numberOfInputs <= 0)
		this->numberOfInputs = 1;

	this->weights = new double[numberOfInputs];//tworzymy tablice wag, zalezna od ilosci wejsc
	for(int i = 0; i < this->numberOfInputs; i++)
		this->weights[i] = getRandomDouble();//Wagi wi są przypadkowymi liczbami zmiennoprzecinkowymi
}

double Adaline::getRandomDouble()
{
	return ((double)rand()/(double)RAND_MAX);
}

Adaline::Adaline() {//Konstruktor domyślny
	srand(time(NULL));
	this->learningRate = 0.01;
	this->EMax=0.0001;

	this->numberOfInputs = 3;
	if(this->numberOfInputs <= 0)
		this->numberOfInputs = 1;

	this->weights = new double[numberOfInputs];//tworzymy tablice wag, zalezna od ilosci wejsc
	for(int i = 0; i < this->numberOfInputs; i++)
		this->weights[i] = getRandomDouble();//Wagi wi są przypadkowymi liczbami zmiennoprzecinkowymi
}

void Adaline::getTestData(double inputData[][pixelsPerLetters],int expectedResults[])
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
