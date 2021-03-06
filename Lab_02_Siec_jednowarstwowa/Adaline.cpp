﻿#include <iostream>
#include <ctime>
#include "Adaline.h"

//ucz sie, czyli:
void Adaline::learn(const double inputs[],int expectedResult) {

		error=0.0;
		delta=expectedResult-getSum(inputs);

		changeWeights(inputs);

		error+=delta*delta;
}

double Adaline::getSum(const double inputs[])
{
	double Sum=0;
	for(int i=0; i<this->numberOfInputs; i++)
		Sum+=this->weights[i]*inputs[i];//suma wejść przemnożonych przez wagi
										//if(sum>1) return 1;//FUNKCJA AKTYWACYJNA
										//else return 0;
	return Sum;
}
int Adaline::activationFunction(double Sum)
{
	if(Sum>0.5)
		return 1;
	else 
		return 0;
}
int Adaline::getResult(const double inputs[]) 
{
	for(int i=0; i<numberOfLetters; i++)
	{
		if(activationFunction(getSum(inputs))==1)
			return 1;
		else return 0;
	}
}

void Adaline::changeWeights(const double inputs[])
{
	for(int i=0; i<this->numberOfInputs; i++)
		this->weights[i]+=this->learningRate*delta*inputs[i];//współczynnik uczenia*błąd lokalny*xi
}//deltawij = xj(di-yi) <- Osowski, (2.4) str. 19; Działanie uczenia jest przyśpieszone poprzez pomnożenie deltawij przez współczynnik uczenia

Adaline::Adaline(unsigned numOfInputs,double trainingRate,double ErrorMax) {
	srand(time(NULL));
	this->learningRate = trainingRate;
	
	this->EMax=ErrorMax;

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