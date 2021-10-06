
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareFunction(string a, string b) {
	return a<b;
}

int main()
{
	string input = "";
	vector <string> words;
	while (getline(cin, input)) {
		if (input.empty()) {
			break;
		}
		words.push_back(input);
	}

	//for (int i = 0; i < words.size(); i++)
	//	cout << words[i] << endl;

	sort(words.begin(), words.end(), compareFunction);

	for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}

