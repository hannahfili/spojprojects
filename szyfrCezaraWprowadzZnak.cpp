#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void shift(string, int);
int main()
{
	int number = 0;
	string sentence = "";
	cout << "Wprowadz liczbe z zakresu <0,25>: ";
	cin >> number;
	while (!(number >= 1 && number <= 25)) {
		cout << "Wprowadzono niepoprawna liczbe. Wprowadz liczbe jeszcze raz" << endl;
		cin >> number;
	}
		
	cin.ignore();
	getline(cin, sentence);
	shift(sentence,number);
}
void shift(string sentence, int number) {
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//cout << abc.length() << endl;
	bool letterFound = false;
	int* indexArray;
	indexArray = new int[sentence.length()];
	int a = 0;
	//length=26
	for (int i = 0; i < sentence.length(); i++) {
		//cout << endl;
		for (int j = 0; j < abc.length(); j++) {
			letterFound = false;
			//cout << "sentence: " << sentence[i] << "\tabc: " << abc[j] << " ";
			if (sentence[i] == abc[j]) {
				indexArray[i] = j;
				letterFound = true;
				break;
			}
		}
		if (!letterFound)
			indexArray[i] = -1;
	}
	/*for (int i = 0; i < sentence.length(); i++) {
		cout << indexArray[i] << " ";
	}*/
	for (int i = 0; i < sentence.length(); i++) {
		if (indexArray[i] != -1) {
			indexArray[i] += number;
			if (indexArray[i] > 25)
				indexArray[i] = indexArray[i] % 26;
		}
	}
	for (int i = 0; i < sentence.length(); i++) {
		if (indexArray[i] != -1)
			sentence[i] = abc[indexArray[i]];
	}
	cout << number<<sentence << endl;
	delete[] indexArray;
}
