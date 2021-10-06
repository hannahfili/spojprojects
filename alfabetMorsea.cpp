#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
void setMorseEntries(vector<string> &morseLetters) {
	morseLetters.push_back(".-");
	morseLetters.push_back("-...");
	morseLetters.push_back("-.-.");
	morseLetters.push_back("-..");
	morseLetters.push_back(".");
	morseLetters.push_back(".-..");
	morseLetters.push_back("--.");
	morseLetters.push_back("....");
	morseLetters.push_back("..");
	morseLetters.push_back(".---");
	morseLetters.push_back("-.-");
	morseLetters.push_back("..-.");
	morseLetters.push_back("--");
	morseLetters.push_back("-.");
	morseLetters.push_back("---");
	morseLetters.push_back(".--.");
	morseLetters.push_back("--.-");
	morseLetters.push_back(".-.");
	morseLetters.push_back("...");
	morseLetters.push_back("-");
	morseLetters.push_back("..-");
	morseLetters.push_back("...-");
	morseLetters.push_back(".--");
	morseLetters.push_back("-..-");
	morseLetters.push_back("-.--");
	morseLetters.push_back("--..");
}
void setDictionaryEntries(map<string, string> &latinToMorseDictionary) {
	
	string latinLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector<string> morseLetters;
	setMorseEntries(morseLetters);
	string key = "";

	for (int i = 0; i < latinLetters.size(); i++) {
		key = latinLetters[i];
		latinToMorseDictionary[key] = morseLetters[i];
	}

}
string translateLatinToMorse(string input, map<string, string> &latinToMorseDictionary) {
	string translatedWord = "";
	string letterToFind = "";
	string wordInMorse = "";
	for (int i = 0; i < input.size(); i++) {

		letterToFind = toupper(input[i]);

		if (latinToMorseDictionary.find(letterToFind) != latinToMorseDictionary.end()) {
			wordInMorse = latinToMorseDictionary[letterToFind];
			translatedWord.append(wordInMorse);
			translatedWord.append("/");
		}
		else if (letterToFind == " ") {
			translatedWord.append("/");
		}
	}
	return translatedWord;
}
int main()
{
	map<string, string> latinToMorseDictionary;
	setDictionaryEntries(latinToMorseDictionary);

	string input = "";
	while (getline(cin,input,'\n')) {
		cout << translateLatinToMorse(input, latinToMorseDictionary) << endl;
	}
}

