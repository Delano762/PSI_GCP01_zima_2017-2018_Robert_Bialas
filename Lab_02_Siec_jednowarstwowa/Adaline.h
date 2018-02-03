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


	double error; //blad globalny (po podniesieniu do kwadratu, podzieleniu przez 2 daje MSE)
	double delta; //jest to wyliczona roznica (dodawana do wag)

	double *weights;
	Adaline(unsigned numOfInputs,double trainingRate);
	Adaline();
	double getRandomDouble();
	void getTestData(double[][pixelsPerLetters],int[]);
	void learn(const double inputs[],int expectedResult);
	int getResult(const double inputs[]);
	void changeWeights(double ,int,const double inputs[]);

};

