class Perceptron {
public:

	unsigned numberOfInputs;
	double learningRate;

	double *weights;
	Perceptron(unsigned numOfInputs,double trainingRate);
	Perceptron();
	double getRandomDouble();
	void learn(const int inputs[],int expectedResult);
	int getResult(const int inputs[]);
	void changeWeights(int actualResult,int desiredResult,const int inputs[]);
};

