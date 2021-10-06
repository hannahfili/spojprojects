
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdlib>
using namespace std;
void shiftBack(string, int);
int main()
{
	int number = 0;
	int helperNumber = 0;
	string sentence = "";
	cout << "Wprowadz liczbe z zakresu <1,25>, a po niej bez spacji zdanie, ktore program ma odszyfrowac:" << endl;
	getline(cin, sentence);
	while (number == 0) {
		helperNumber = atoi(sentence.c_str());
		if (helperNumber >= 1 && helperNumber <= 25) {
			number = helperNumber;
		}
		else {
			cout << "Wprowadzono niepoprawna liczbe.\nWprowadz liczbe z zakresu <1,25>, a po niej bez spacji zdanie, ktore program ma odszyfrowac:" << endl;
			getline(cin, sentence);
		}
	}
	shiftBack(sentence, number);
	
}
void shiftBack(string sentence, int number) {
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	bool letterFound = false;
	int* indexArray;
	indexArray = new int[sentence.length()];
	int a = 0;
	for (int i = 0; i < sentence.length(); i++) {
		for (int j = 0; j < abc.length(); j++) {
			letterFound = false;
			if (sentence[i] == abc[j]) {
				indexArray[i] = j;
				letterFound = true;
				break;
			}
		}
		if (!letterFound)
			indexArray[i] = -1;
	}
	
	for (int i = 0; i < sentence.length(); i++) {
		if (indexArray[i] != -1) {
			indexArray[i] += 26-number;
			if (indexArray[i] > 25)
				indexArray[i] = indexArray[i] % 26;
		}
	}
	for (int i = 0; i < sentence.length(); i++) {
		if (indexArray[i] != -1)
			sentence[i] = abc[indexArray[i]];
	}
	for (int i = 0; i < sentence.length(); i++) {
		if (!isdigit(sentence[i]))
			cout << sentence[i];
	}
	delete[] indexArray;
}

