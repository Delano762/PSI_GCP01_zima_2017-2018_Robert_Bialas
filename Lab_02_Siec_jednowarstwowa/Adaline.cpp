#include "Adaline.h"

Adaline::Adaline(double _learningRate)
{
	delta = 0;
	numberOfWeights = PIXEL_AMOUNT;
	numberOfSets = LETTER_AMOUNT;
	learningRate = _learningRate;
	EMax = 0.1;
	error = 0.0;
	weights = new double[numberOfWeights];
	
	for (int i = 0; i < PIXEL_AMOUNT; i++)
		this->weights[i] = getRandomDouble(); //Krok 2

	//wczytanie z pliku danych uczacych
	readTestData();
}

//wczytanie danych ucz�cych z pliku
void Adaline::readTestData()
{
	fstream file;
	file.open("data_for_learning.txt");

	if (!file.good()) {
		cout << "--------- I can't open the file with learning data ---------" << endl;
		system("PAUSE");
		exit(0);
	}

	//wczytuj z pliku dop�ki s� dane
	while (!file.eof())							//Krok 4
		for (int i = 0; i < LETTER_AMOUNT; i++) { // i oznacza indeks litery
			for (int j = 0; j < PIXEL_AMOUNT; j++) // j oznacza ilosc pikseli na dan� litere
				file >> this->inputData[i][j]; //wczytywanie do tablicy z wejsciami

			file >> this->expectedResults[i]; //wczytanie z pliku czy dana litera jest duza (1) lub mala (0)
		}

	file.close();
}

//losuje double'a z przedzialu <0;1>
double Adaline::getRandomDouble()
{
	double randValue = ((double)rand() / (double)RAND_MAX);
	return randValue;
}

//funkcja aktywacji - funkcja progowa unipolarna
bool Adaline::activationFunction(double sum)
{
	if (sum > 0.5)
		return true;
	else
		return false;
}

//zwraca sume danego wejscia
double Adaline::getSum(int letter[], double * weights)
{
	double sum = 0.0;
	for (int i = 0; i < numberOfWeights; i++)
		sum += letter[i] * weights[i];
	return sum;
}

//funkcja uczaca
void Adaline::learn()
{
	cout << endl << "ADALINE - LEARNING" << endl;
	
	bool acceptableError = false; //zmienna, stwierdzajaca czy blad jest mozliwy do zaakceptowania

										//KROK 3
	int epoch = 0; //numer epoki

	/*
	for (int i = 0; i < numberOfWeights; i++)
		cout << "Weights are: w" << i+1 << " = " << weights[i] << endl;;
	cout << endl;
	*/

	do {
		epoch++; // zwiekszenie epoki
		error = 0.0; //zerowanie glownego bledu w celu sprawdzenia bledow podczas jednej iteracji
		for (int i = 0; i<numberOfSets; i++) {

			//obliczanie roznicy pomiedzy wynikiem oczekiwanym a wynikiem otrzymanym
			delta = expectedResults[i] - getSum(inputData[i], weights);  // tj - yj, tu sie rozupoczyna krok 6

			//aktualizowanie wag					KROK 5
			for (int j = 0; j < numberOfWeights; j++)
				weights[j] += learningRate*delta*inputData[i][j];

			//aktualizowanie bledu glownego
			error += delta*delta;
		}
		error /= 2; //zakonczenie kroku 6

		//porownywanie bledu z progiem
		if (error>EMax) { //EMax
			acceptableError = false; //KROK 8
		}
		else {
			acceptableError = true;
		}
	} while (!acceptableError); //KROK 7

	cout << "Epoch: " << epoch << endl;
	cout << "MSE error: " << error << endl;
	/*
	for (int i = 0; i < numberOfWeights; i++)
		cout << "Weights are: w" << i+1 << " = " << weights[i] << endl;
	*/
}

//funkcja testujaca
void Adaline::test()
{
	cout << "Test letters:" << endl;
	for (int i = 0; i<numberOfSets; i++) {
		cout << "Letter " << setTestLetters[i] << " is: ";
		if (activationFunction(getSum(setTest[i], weights))) {
			cout << "big";
		}
		else {
			cout << "small";
		}
		cout << endl;
	}
}
