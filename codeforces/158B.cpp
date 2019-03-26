#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[4] = { 0, };

int main() {

	int n = 0;
	cin >> n;

	int* input = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		num[input[i] - 1]++;
	}

	int count = num[3];

	while (num[2] > 0) {
		if (num[0] == 0) {
			count = count + num[2];
			num[2] = 0;
		}
		else if (num[0] > num[2]) {
			count = count + num[2];
			num[0] = num[0] - num[2];
			num[2] = 0;
		}
		else if (num[2] > num[0]) {
			count = count + num[0];
			num[2] = num[2] - num[0];
			num[0] = 0;
		}
		else {
			count = count + num[0];
			num[2] = 0;
			num[0] = 0;
		}
	}

	if (num[1] > 0) {
		count = count + num[1] / 2;
		if (num[1] % 2 != 0) {
			count++;
			if (num[0] > 0) {
				num[0] = num[0] - 2;
			}
		}
		num[1] = 0;
	}

	if (num[0] > 0) {
		count = count + num[0] / 4;
		if (num[0] % 4 != 0) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}