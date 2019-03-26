#include <iostream>
using namespace std;

int main() {
	int n = 0, m = 0;
	
	cin >> n;
	cin >> m;

	int* hnum = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> hnum[i];
	}

	long long time = 0;
	long long pos = 1;
	int taskNum = 0;
	while (m > 0) {
		long long dest = hnum[taskNum];
		if (pos == dest) {
			m--;
			taskNum++;
		}
		else {
			if (pos < dest) {
				time = time + (dest - pos);
			}
			else {
				time = time + (long long)n - pos + dest;
			}
			pos = dest;
		}
	}

	cout << time << endl;

	return 0;
}