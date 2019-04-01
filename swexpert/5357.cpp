#include <iostream>
#include <vector>
using namespace std;

int main() {

	int test_case = 0;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {
		int answer = 0;
		int N = 0, H = 0;
		cin >> N;
		cin >> H;

		int totalLength = 0;
		vector<int> meters;
		for (int n = 0; n < N; n++) {
			int temp;
			cin >> temp;
			totalLength = totalLength + temp;
			meters.push_back(temp);
		}

		vector<int> status;
		for (int o = 0; o < N; o++) {
			int temp;
			cin >> temp;
			status.push_back(temp);
		}

		if (status[0] == 0) {
			status[0] = 1;
			answer++;
		}

		if (status[N - 1] == 0) {
			status[N - 1] = 0;
			answer++;
		}

		int sum = 0;
		for (int i = 1; i < N-1; i++) {
			
			if (status[i] == 1) {
				sum = 0;
			}
			else {
				sum = sum + meters[i];
				if (sum >= H) {
					sum = 0;
					answer++;
				}
			}
		}

		cout << "#" << t << " " << answer << endl;
	}

	return 0;
}