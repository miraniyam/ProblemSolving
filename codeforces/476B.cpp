#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main() {

	string input;
	cin >> input;

	string dinput;
	cin >> dinput;

	int inputSum = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '+') {
			inputSum = inputSum + 1;
		}
		else if (input[i] == '-') {
			inputSum = inputSum - 1;
		}
	}

	int dinputSum = 0;
	int notRecognized = 0;
	for (int i = 0; i < dinput.size(); i++) {
		if (dinput[i] == '+') {
			dinputSum = dinputSum + 1;
		}
		else if (dinput[i] == '-') {
			dinputSum = dinputSum - 1;
		}
		else {
			notRecognized++;
		}
	}

	cout << fixed;
	cout.precision(12);

	if (notRecognized == 0 && dinputSum == inputSum) {
		cout << 1.0f << endl;
	}
	else {
		double numberOfCase = pow(2, notRecognized);
		int max = dinputSum + notRecognized;
		int count = 0;
		while (count <= notRecognized) {
			if (max == inputSum) {
				break;
			}
			count++;
			max = max - 2;
		}

		if (max != inputSum) {
			cout << (double)0.0f << endl;
		}
		else {
			double answer = 1.0f;
			for (double i = notRecognized; i > notRecognized - count; i--) {
				answer = answer * i;
			}
			for (double i = count; i > 0; i--) {
				answer = answer / i;
			}
			cout << answer / numberOfCase << endl;
		}
	}

	return 0;
}