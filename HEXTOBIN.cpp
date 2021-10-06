#include <iostream>
#include <map>
#include <string>


using namespace std;

void setEntries(map<string, string>& hexToBinDictionary) {
	string keys = "0123456789ABCDEF";
	string hexKey = "";
	string binEntry = "";

	int counterToEight = 0;
	int counterToFour = 0;


	for (int i = 0; i < keys.size(); i++) {
		binEntry = "";
		hexKey = keys[i];

		//ustaw pierwsz� cyfr�
		if (i < 8) {
			binEntry.append("0");
		}
		else
			binEntry.append("1");

		//ustaw drug� cyfr�
		if (counterToEight < 4) {
			binEntry.append("0");
		}
		else {
			binEntry.append("1");
		}
		counterToEight++;
		if (counterToEight == 8)
			counterToEight = 0;

		//ustaw trzeci� cyfr�

		if (counterToFour < 2) {
			binEntry.append("0");
		}
		else {
			binEntry.append("1");
		}
		counterToFour++;
		if (counterToFour == 4) {
			counterToFour = 0;
		}

		//ustaw czwart� cyfr�

		if (i % 2 == 0) {
			binEntry.append("0");
		}
		else
			binEntry.append("1");

		hexToBinDictionary[hexKey] = binEntry;

		//cout << hexKey << "-->" << binEntry << endl;

	}
}

string translateHexToBin(string input, map<string, string>& hexToBinDictionary) {
	string translatedWord = "";
	string numberInBin = "";
	for (int i = 0; i < input.size(); i++) {
		input[i]=toupper(input[i]);
	}

	if (hexToBinDictionary.find(input) != hexToBinDictionary.end()) {
		numberInBin = hexToBinDictionary[input];
		translatedWord.append(numberInBin);
	}

	return translatedWord;
}

int main()
{
	map<string, string> hexToBinDictionary;
	setEntries(hexToBinDictionary);

	string input = "";

	while (getline(cin, input, '\n')) {
		cout << translateHexToBin(input, hexToBinDictionary) << endl;
	}
}
