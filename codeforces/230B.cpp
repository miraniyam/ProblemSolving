#include <iostream>
#include <math.h>
using namespace std;
long long input[100001];

int main() {

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
		
		long long base = input[i];
		long long limit = sqrt(base);

		if (limit*limit == base) {
			if (limit < 2) {
				cout << "NO" << endl;
			}
			else if (limit == 2) {
				cout << "YES" << endl;
			}
			else if (base % 2 == 0) {
				cout << "NO" << endl;
			}
			else {
				int count = 3;
				for (int j = 3; j <= sqrt(limit); j = j+2) {
					if (base %j == 0) {
						cout << "NO" << endl;
						count++;
						break;
					}
				}
				if (count == 3) {
					cout << "YES" << endl;
				}
			}
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}