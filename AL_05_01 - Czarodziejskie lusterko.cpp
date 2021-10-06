#include <iostream>
#include <string>
#include <sstream>


using namespace std;

string mirror(unsigned long long int);
unsigned long long int power(unsigned long long int, int);
void createNewNumber(string);

int main()
{
	int count = 0;
	unsigned long long int number = 0;
	string binNumberStr = "";


	while (cin >> number) {
		//cout << "jestem w ifie" << endl;
		binNumberStr = mirror(number);
		//cout << "binNumberStr: " << binNumberStr << endl;
		createNewNumber(binNumberStr);

		
	}
	return 0;
}

	string mirror(unsigned long long int number) {
		//cout << "jestem w mirror" << endl;
		int remainder = 0;
		string binNumberStr = "";
		stringstream ss;
		string remainderStr = "";

		while (number != 0) {

			remainder = number % 2;
			number = number / 2;

			ss.str(string());
			ss << remainder;
			remainderStr = ss.str();
			binNumberStr += remainderStr;
			//cout << binNumberStr << endl;
			//getchar();
		}
		return binNumberStr;
	}
	void createNewNumber(string binNumberStr) {

		unsigned long long int decMirrored = 0;

		for (int i = binNumberStr.length(); i >= 0; i--) {
			cout << i << "\t" << binNumberStr[i] << endl;
			if (binNumberStr[i] == '1') {
				decMirrored += power(2, binNumberStr.length() - 1 - i);
			}
		}
		cout << decMirrored << endl;
	}
	unsigned long long int power(unsigned long long int base, int exponent) {
		unsigned long long int result = 1;
		for (int i = 0; i < exponent; i++) {
			result *= base;
		}
		return result;
	}