
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void divideStringIntoPieces(string input, vector <string> & output) {
	string word = "";
	
	for (int i = 0; i < input.length(); i++) {
		string letterConvertedToString(1, input[i]);
		if (i == input.length() - 1) {
			word.append(letterConvertedToString);
			output.push_back(word);
			word = "";
		}
		else if (letterConvertedToString != " ") {
			word.append(letterConvertedToString);
		}
		else {
			output.push_back(word);
			word = "";
		}
	}
}

int compareSubstringSetWithStringSet(vector <string> & substringOfBiggerSet, vector <string> & biggerSet,
	vector <string> & differenceSet) {
	
	int numberOfForgottenWords = 0;
	int beginningOfIteration = 0;

	int i = 0;
	int j = 0;

	for (i = 0; i < substringOfBiggerSet.size(); i++) {
		for (j = beginningOfIteration; j < biggerSet.size(); j++) {
			if (substringOfBiggerSet[i] == biggerSet[j]) {
				beginningOfIteration=j+1;
				break;
			}
			else {
				numberOfForgottenWords++;
				differenceSet.push_back(biggerSet[j]);
				beginningOfIteration = j+1;
			}
		}
	}
	if (j != biggerSet.size() - 1) {
		for (int k = j+1; k < biggerSet.size(); k++) {
			numberOfForgottenWords++;
			differenceSet.push_back(biggerSet[k]);
		}
	}
	

	return numberOfForgottenWords;
}

bool compareFunction(string a, string b) {
	return a < b;
}

int main()
{
	int numberOfForgottenWords = 0;
	string originalSongWords= "";
	string rememberedSongWords = "";
	vector <string> words;
	getline(cin, originalSongWords);
	getline(cin, rememberedSongWords);

	vector <string> originalSongWordsSeparately;
	vector <string> rememberedSongWordsSeparately;
	vector <string> wordsNotRemembered;

	divideStringIntoPieces(originalSongWords, originalSongWordsSeparately);
	divideStringIntoPieces(rememberedSongWords, rememberedSongWordsSeparately);


	numberOfForgottenWords = compareSubstringSetWithStringSet(rememberedSongWordsSeparately, originalSongWordsSeparately, wordsNotRemembered);
	sort(wordsNotRemembered.begin(), wordsNotRemembered.end(), compareFunction);


	cout << numberOfForgottenWords << endl;
	if (numberOfForgottenWords > 0) {
		for (int i = 0; i < numberOfForgottenWords; i++) {
			cout << wordsNotRemembered[i] << endl;
		}
	}
	
	return 0;
}
