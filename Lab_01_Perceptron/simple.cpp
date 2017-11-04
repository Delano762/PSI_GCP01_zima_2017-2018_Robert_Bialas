#include <iostream>
#include <string>
#include "Perceptron.h"

using namespace std;
void LogicFunction(int &,int[]);
int main() {
	double bias=1;
	double
		ONE_ONE[] ={bias,1,1},
		ZERO_ONE[] ={bias,0,1},
		ONE_ZERO[] ={bias,1,0},
		ZERO_ZERO[] ={bias,0,0};
	int numberOfInputs=sizeof(ONE_ONE)/sizeof(ONE_ONE[0]),numberOfEpochs=0,functionIndex;
	int *function = new int[3];
	string functionNames[] ={"AND","NAND","OR","XOR","NOR"};
	double learningRate=0.1;
	//cout<<"Podaj liczbe wejsc i: ";
	//cin>>numberOfInputs;
	//cout<<"Podaj ilosc epok: ";
	//cin>>numberOfEpochs;
	cout<<"Lista funkcji:\nAND -	1\nNAND -	2\nOR -	3\nXOR -	4 (nie dziala, z racji ze XOR nie jest podzielny linearnie)\nNOR -	5\nWybierz funkcje: ";
	cin>>functionIndex;
	LogicFunction(functionIndex,function);
	//cout<<function[0]<<" "<<function[1]<<" "<<function[2]<<" "<<function[3]<<endl;
	Perceptron perceptron(numberOfInputs,learningRate);

	cout << functionNames[functionIndex-1] << " - wyniki PRZED uczeniem" << endl;
	cout << "Wejscie (0,0) - wynik: " << perceptron.getResult(ZERO_ZERO) << endl;
	cout << "Wejscie (0,1) - wynik: " << perceptron.getResult(ZERO_ONE) << endl;
	cout << "Wejscie (1,0) - wynik: " << perceptron.getResult(ONE_ZERO) << endl;
	cout << "Wejscie (1,1) - wynik: " << perceptron.getResult(ONE_ONE) << endl;

	//for(int i=0; i<numberOfEpochs; i++)
	bool done=false;
	while(done==false)
	{
		numberOfEpochs++;
		done=true;
		perceptron.learn(ZERO_ZERO,function[0]);
		perceptron.learn(ZERO_ONE,function[1]);
		perceptron.learn(ONE_ZERO,function[2]);
		perceptron.learn(ONE_ONE,function[3]);
		if(perceptron.getResult(ZERO_ZERO)!=function[0])done=false;
		if(perceptron.getResult(ZERO_ONE)!=function[1])done=false;
		if(perceptron.getResult(ONE_ZERO)!=function[2])done=false;
		if(perceptron.getResult(ONE_ONE)!=function[3])done=false;
	}


	cout << endl << functionNames[functionIndex-1] << " - wyniki PO uczeniu" << endl;
	cout << "Wejscie (0,0) - wynik: " << perceptron.getResult(ZERO_ZERO) << endl;
	cout << "Wejscie (0,1) - wynik: " << perceptron.getResult(ZERO_ONE) << endl;
	cout << "Wejscie (1,0) - wynik: " << perceptron.getResult(ONE_ZERO) << endl;
	cout << "Wejscie (1,1) - wynik: " << perceptron.getResult(ONE_ONE) << endl;
	cout << "Liczba wykonanych epok: " << numberOfEpochs << endl;

	system("pause");
	return 0;
}
void LogicFunction(int &functionIndex,int function[])
{
	switch(functionIndex)
	{
	case 1://AND
		function[0]=0; function[1]=0; function[2]=0; function[3]=1; break;
	case 2://NAND
		function[0]=1; function[1]=1; function[2]=1; function[3]=0; break;
	case 3://OR
		function[0]=0; function[1]=1; function[2]=1; function[3]=1; break;
	case 4://XOR
		function[0]=0; function[1]=1; function[2]=1; function[3]=0; break;
	case 5://NOR
		function[0]=1; function[1]=0; function[2]=0; function[3]=0; break;
	default://DOMYŒLNA FUNKCJA TO AND
		function[0]=0; function[1]=0; function[2]=0; function[3]=1; functionIndex=1;  break;
	}
}