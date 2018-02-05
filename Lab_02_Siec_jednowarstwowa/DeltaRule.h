#pragma once

#define numberOfLetters 20
#define pixelsPerLetters 35
#include <iostream>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class DeltaRule {
public:

	unsigned numberOfInputs;
	double learningRate;


	double EMax;
	int epoch;
	double sum;
	double output; //przechowuje aktualna wartosc (porownywana z wartoscia oczekiwana)


	double error=0.0; //blad globalny (po podniesieniu do kwadratu, podzieleniu przez 2 daje MSE)
	double delta; //jest to wyliczona roznica (dodawana do wag)

	double *weights;
	DeltaRule(unsigned numOfInputs,double trainingRate,double ErrorMax);
	double getRandomDouble();
	void learn(const double inputs[],int expectedResult);
	double activationFunction(double);
	double derivativeActivationFunction(double);
	int getResult(const double inputs[]);
	double getSum(const double inputs[]);
	void changeWeights(const double inputs[]);

};

