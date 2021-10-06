
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

void checkPassword(string);

int main()
{
	string word;

	while(cin >> word){
		checkPassword(word);
		cout << endl;
	}

}

void checkPassword(string word) {
	int tabWord1[16];
	int tabWord2[16];
	int tabNumbers[20];
	int addNumbers[10];
	
	string abc = "ABCDEFGHIJKLMNOP";
	string s = "";
	stringstream ss;
	int number = 0;

	//utworzenie tablicy szyfrowej A-P 0-15
	for (int i = 0; i < 16; i++) {
		tabWord1[i] = i;
		//cout << tabWord1[i]<< endl;
	}
	//utworzenie tablicy szyfrowej A-P 0-16-...-240
	for (int i = 0; i < 16; i++) {
		tabWord2[i] = number;
		number+=16;
		//cout << tabWord2[i] << endl;
	}
	
	for (int i = 0; i < word.length(); i++) {
		for (int j = 0; j < abc.length(); j++) {
			if (word[i] == abc[j]) {
				if (i % 2 == 0) {
					tabNumbers[i] = tabWord1[j];
				}
				else
					tabNumbers[i] = tabWord2[j];
			}
		}
		//cout << tabNumbers[i] << " ";
	}
	////tworzenie tablicy sum z wprowadzonych liter

	for (int i = 0; i < 10; i++) {
		addNumbers[i] = tabNumbers[2 * i] + tabNumbers[2*i + 1];
		cout << char(addNumbers[i]);
	}


}


