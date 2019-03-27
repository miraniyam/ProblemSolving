#include <iostream>
using namespace std;

int main() {
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		long double n = 0, m = 0;
		cin >> n;
		cin >> m;

		n = n > m - n ? m - n : n;

		long double answer = 1;
		long double nn = n;
		
		for (int i = 0; i < n; i++) {
			answer = answer * (m - i);
		}

		for (int i = 2; i <= n; i++) {
			answer = answer / i;
		}

		cout << (int)answer << endl;
	}
	return 0;
}