#include "Adaline.h"
#include "DeltaRule.h"

int main()
{
	double learningRate = 0.01; //wspolczynnik uczenia

	cout << "Learning Rate: " << learningRate << endl;

	//Adaline
	Adaline adaline(learningRate);
	adaline.learn();
	adaline.test();

	//DeltaRule
	DeltaRule deltaRule(learningRate);
	deltaRule.learn();
	deltaRule.test();

	system("PAUSE");
	return 0;
}
