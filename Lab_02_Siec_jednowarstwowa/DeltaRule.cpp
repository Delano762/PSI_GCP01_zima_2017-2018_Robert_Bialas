#include <iostream>
#include <ctime>
#include "DeltaRule.h"


//ucz sie, czyli:
void DeltaRule::learn(const double inputs[],int expectedResult) {

	error=0.0;
	output=activationFunction(getSum(inputs));
	delta=expectedResult-output;

	changeWeights(inputs);

	error+=delta*delta;
}

double DeltaRule::getSum(const double inputs[])
{
	double Sum=0;
	for(int i=0; i<this->numberOfInputs; i++)
		Sum+=this->weights[i]*inputs[i];//suma wejść przemnożonych przez wagi
										//if(sum>1) return 1;//FUNKCJA AKTYWACYJNA
										//else return 0;
	return Sum;
}
double DeltaRule::activationFunction(double Sum)
{
	return (1/(1+exp(-1.0*Sum)));
}
double DeltaRule::derivativeActivationFunction(double Sum)
{
	return (1.0*exp(-1.0*Sum)) / (pow(exp(-1.0*Sum) + 1, 2));
}
int DeltaRule::getResult(const double inputs[])
{
	for(int i=0; i<numberOfLetters; i++)
	{
		if(activationFunction(getSum(inputs))>0.5)
			return 1;
		else return 0;
	}
}

void DeltaRule::changeWeights(const double inputs[])
{
	for(int i=0; i<this->numberOfInputs; i++)
		this->weights[i]+=this->learningRate*delta*derivativeActivationFunction(getSum(inputs))*inputs[i];//współczynnik uczenia*błąd lokalny*xi
}//deltawij = xj(di-yi) <- Osowski, (2.4) str. 19; Działanie uczenia jest przyśpieszone poprzez pomnożenie deltawij przez współczynnik uczenia

DeltaRule::DeltaRule(unsigned numOfInputs,double trainingRate,double ErrorMax) {
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

double DeltaRule::getRandomDouble()
{
	return ((double)rand()/(double)RAND_MAX);
}