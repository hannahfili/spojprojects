
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct numberAndName {
	string number;
	string name;
};

void setDictionary0to19Entries(map<int, string>& dicionary1to19) {
	dicionary1to19[0] = "zero";
	dicionary1to19[1] = "jeden";
	dicionary1to19[2] = "dwa";
	dicionary1to19[3] = "trzy";
	dicionary1to19[4] = "cztery";
	dicionary1to19[5] = "piec";
	dicionary1to19[6] = "szesc";
	dicionary1to19[7] = "siedem";
	dicionary1to19[8] = "osiem";
	dicionary1to19[9] = "dziewiec";
	dicionary1to19[10] = "dziesiec";
	dicionary1to19[11] = "jedenascie";
	dicionary1to19[12] = "dwanascie";
	dicionary1to19[13] = "trzynascie";
	dicionary1to19[14] = "czternascie";
	dicionary1to19[15] = "pietnascie";
	dicionary1to19[16] = "szesnascie";
	dicionary1to19[17] = "siedemnascie";
	dicionary1to19[18] = "osiemnascie";
	dicionary1to19[19] = "dziewietnascie";
}
void setDictionaryOfDecadsEntries(map<int, string>& dicionaryOfDecads) {
	dicionaryOfDecads[2] = "dwadziescia";
	dicionaryOfDecads[3] = "trzydziesci";
	dicionaryOfDecads[4] = "czterdziesci";
	dicionaryOfDecads[5] = "piecdziesiat";
	dicionaryOfDecads[6] = "szescdziesiat";
	dicionaryOfDecads[7] = "siedemdziesiat";
	dicionaryOfDecads[8] = "osiemdziesiat";
	dicionaryOfDecads[9] = "dziewiecdziesiat";
}
void setDictionaryOfHundredsEntries(map<int, string>& dicionaryOfHundreds) {
	dicionaryOfHundreds[1] = "sto";
	dicionaryOfHundreds[2] = "dwiescie";
	dicionaryOfHundreds[3] = "trzysta";
	dicionaryOfHundreds[4] = "czterysta";
	dicionaryOfHundreds[5] = "piecset";
	dicionaryOfHundreds[6] = "szescset";
	dicionaryOfHundreds[7] = "siedemset";
	dicionaryOfHundreds[8] = "osiemset";
	dicionaryOfHundreds[9] = "dziewiecset";
}

int findTheClosestCounter(int number){

	vector<int>listOfPossibleCounters;

	int countersTable[4] = { 2, 5, 8, 11 };
	int countersTableLength = 4;


	for (int i = 0; i < countersTableLength; i++) {
		if (countersTable[i] > number) {
			listOfPossibleCounters.push_back(countersTable[i]);
		}
	}

	int minimum = listOfPossibleCounters[0];

	for (int i = 1; i < listOfPossibleCounters.size(); i++) {
		if (listOfPossibleCounters[i] < minimum) {
			minimum = listOfPossibleCounters[i];
		}
	}

	return minimum;
}

map<string, string> divideNumberToTrios(string numberToDivide) {
	int counter = 0;
	int closestCounter = 0;
	
	map<string, string> mapOfTrios;
	string trio = "";
	string charToString = "";

	for (int i = numberToDivide.length() - 1; i >= 0; i--) {
		if (i == 0 && counter != 2 && counter != 5 && counter != 8 && counter != 11) {
			//cout << "counter: " << counter << endl;
			closestCounter = findTheClosestCounter(counter);
			//cout << "closestCounter: " << closestCounter << endl;
			counter = closestCounter;
		}
		if (counter == 0 || counter % 3 == 0 || counter % 3 == 1) {
			string charToAppend(1, numberToDivide[i]);
			trio = trio + charToAppend;
		}
		else if (counter == 2 || counter == 5 || counter == 8 || counter == 11) {
			string charToAppend(1, numberToDivide[i]);
			trio = trio + charToAppend;
			reverse(trio.begin(), trio.end());

			switch (counter) {
			case 2:
				mapOfTrios["hundreds"] = trio;
				break;
			case 5:
				mapOfTrios["thousands"] = trio;
				break;
			case 8:
				mapOfTrios["millions"] = trio;
				break;
			case 11:
				mapOfTrios["billions"] = trio;
				break;
			}
			trio = "";
		}
		counter++;
	}
	return mapOfTrios;
}

string convertNumberToText(string number) {

	//cout << "convertToText: number: "<<number << endl;

	string output = "";
	int numberAsInt = atoi(number.c_str());
	int digitAsInt = 0;

	//cout << "convertToText: numberAsInt: " << number << endl;

	map<int, string> dictionary1to19;
	map<int, string> dictionaryOfDecads;
	map<int, string> dictionaryOfHundreds;

	setDictionary0to19Entries(dictionary1to19);
	setDictionaryOfDecadsEntries(dictionaryOfDecads);
	setDictionaryOfHundredsEntries(dictionaryOfHundreds);

	

	if (numberAsInt < 20 && number!="000") {

		//cout << "pierwszy IF" << endl;
		if (dictionary1to19.find(numberAsInt) != dictionary1to19.end()) {
			output = (*dictionary1to19.find(numberAsInt)).second;
			output.append(" ");
		}
	}
	else if (numberAsInt >= 20 && numberAsInt < 100) {
		//cout << "drugi IF" << endl;
		
		digitAsInt = number[0] - '0';

		if (dictionaryOfDecads.find(digitAsInt) != dictionaryOfDecads.end()) {

			output.append((*dictionaryOfDecads.find(digitAsInt)).second);
			output.append(" ");
		}


		digitAsInt = number[1] - '0';
		if (number[1] != '0' && dictionary1to19.find(digitAsInt) != dictionary1to19.end()) {
			output.append((*dictionary1to19.find(digitAsInt)).second);
			output.append(" ");
		}
	}
	else {

		//cout << "ELSE" << endl;
		//cout << "numberAsString[1] "  << numberAsString[1]  << endl;
		digitAsInt = number[0] - '0';

		if (dictionaryOfHundreds.find(digitAsInt) != dictionaryOfHundreds.end()) {
			output.append((*dictionaryOfHundreds.find(digitAsInt)).second);
			output.append(" ");
		}
		if (number[1] == '1') {
			//cout << "JESTEM W IFIE " << endl;
			string twoDigitsAsString = number.substr(1, 2);
			//cout << "twoDigitsAsString: " << twoDigitsAsString << endl;
			int twoDigits = stoi(twoDigitsAsString);
			if (dictionary1to19.find(twoDigits) != dictionary1to19.end()) {
				output.append((*dictionary1to19.find(twoDigits)).second);
				output.append(" ");
			}

		}
		else {
			//cout << "kolejny ELSE" << endl;
			digitAsInt = number[1] - '0';
			if (number[1] != '0' && dictionaryOfDecads.find(digitAsInt) != dictionaryOfDecads.end()) {
				output.append((*dictionaryOfDecads.find(digitAsInt)).second);
				output.append(" ");
			}

			digitAsInt = number[2] - '0';
			if (number[2] != '0' && dictionary1to19.find(digitAsInt) != dictionary1to19.end()) {
				output.append((*dictionary1to19.find(digitAsInt)).second);
				output.append(" ");
			}
		}



	}


	//cout << "convertToText: output: " << output << endl;
	return output;

}
string addConvertedText(map<string, string> mapToSearch, string keyToFind, string formToAdd) {
	string numberToConvert = "";
	char numberToConvertLastChar = ' ';
	string convertedPartOfNumber = "";

	map<string, string>::iterator wantedPartOfMap = mapToSearch.find(keyToFind);

	if (wantedPartOfMap != mapToSearch.end()) {
		numberToConvert = (*wantedPartOfMap).second;
		
		//cout << "numberToConvert: " << numberToConvert << endl;
		convertedPartOfNumber = convertNumberToText(numberToConvert);
		//cout << "convertedPartOfNumber: " << convertedPartOfNumber << endl;
		if (convertedPartOfNumber != "") {
			convertedPartOfNumber.append(formToAdd);
		}
		

		
	}
	return convertedPartOfNumber;

}

int main()
{
	int numberOfSets = 0;
	string nameOfNumber = "";

	vector <numberAndName>  numbersAndNames;
	numberAndName input;

	cin >> numberOfSets;

	for (int i = 0; i < numberOfSets; i++) {
		cin >> input.number;
		input.name = nameOfNumber;

		numbersAndNames.push_back(input);
	}
	map<string, string> mapOfTrios;

	string finalText = "";

	for (vector <numberAndName>::iterator itr = numbersAndNames.begin(); itr != numbersAndNames.end(); itr++) {
		
		if ((*itr).number != "1000000000000") {
			finalText = "";

			mapOfTrios = divideNumberToTrios((*itr).number);

			/*for (map<string, string>::iterator i = mapOfTrios.begin(); i != mapOfTrios.end(); i++) {
				cout << (*i).first << " --> " << (*i).second << endl;
				cout << convertNumberToText((*i).second) << endl;
			}*/

			string decadePart = addConvertedText(mapOfTrios, "hundreds", " ");
			string thousandPart = addConvertedText(mapOfTrios, "thousands", "tys. ");
			string millionPart = addConvertedText(mapOfTrios, "millions", "mln. ");
			string billionPart = addConvertedText(mapOfTrios, "billions", "mld. ");

			finalText = finalText + billionPart + millionPart + thousandPart + decadePart;
			(*itr).name = finalText;
		}
		else
			(*itr).name = "jeden bln.";
		
	}

	for (vector <numberAndName>::iterator itr = numbersAndNames.begin(); itr != numbersAndNames.end(); itr++) {
		cout << (*itr).name<< endl;
	}


}
