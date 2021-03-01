#include <iostream>
#include <string>

using namespace std;

int main() {

	string input;
	cin >> input;
	string temp = "";
	int result = 0;
	bool MinusFlag = 0;
	cout << input.size();
	for (int i = 0; i <= input.size(); i++) {
		if (input[i] == '+' || input[i] == '-' || input[i] == NULL) {
			
			if (MinusFlag == 1) {

				result -= stoi(temp);
			}
			else {
				result += stoi(temp);
			}
			temp = "";
			if (input[i] == '-') {
				MinusFlag = 1;
			}

		}
		else {
			temp += input[i];
		}

	}



	cout << result;

	return 0;
}