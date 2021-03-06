#pragma once
#define numberOfLetters 20
#define pixelsPerLetters 35
#include <iostream>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Adaline {
public:

	unsigned numberOfInputs;
	double learningRate;


	double EMax;
	int epoch;
	double sum;


	double error=0.0; //blad globalny (po podniesieniu do kwadratu, podzieleniu przez 2 daje MSE)
	double delta; //jest to wyliczona roznica (dodawana do wag)

	double *weights;
	Adaline(unsigned numOfInputs,double trainingRate,double ErrorMax);
	double getRandomDouble();
	void learn(const double inputs[],int expectedResult);
	int activationFunction(double);
	int getResult(const double inputs[]);
	double getSum(const double inputs[]);
	void changeWeights(const double inputs[]);

};

