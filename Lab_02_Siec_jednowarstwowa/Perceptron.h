#define numberOfLetters 20
#define pixelsPerLetters 35
#include <iostream>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Perceptron {
public:

	unsigned numberOfInputs;
	double learningRate;

	double *weights;
	Perceptron(unsigned numOfInputs,double trainingRate);
	double getRandomDouble();
	void learn(const double inputs[],int expectedResult);
	int getResult(const double inputs[]);
	void changeWeights(int actualResult,int desiredResult,const double inputs[]);
};

