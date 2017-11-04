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