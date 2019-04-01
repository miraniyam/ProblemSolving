#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int test_case = 0;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int k = 1, n = 1;

		cin >> n;
		cin >> k;

		vector<double> m;
		for (int i = 0; i < n; i++) {
			double temp;
			cin >> temp;
			m.push_back(temp);
		}

		sort(m.begin(), m.end(), greater<double>());

		double answer = 0;
		for (int i = k-1; i >=0; i--) {
			answer = answer + m[i];
			answer = answer / (double)2;
		}
		cout << "#" << t << " " << answer << endl;
	}

	cin >> test_case;

	return 0;
}