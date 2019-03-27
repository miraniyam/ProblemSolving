#include <iostream>
using namespace std;

int main() {

	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		int num = 0;
		cin >> num;

		int**map = new int*[num];
		for (int i = 0; i < num; i++) {
			map[i] = new int[num];
		}

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				map[i][j] = 0;
			}
		}

		int count = 1;
		int round = 1;
		int n = num;
		int i = 0, j = 0;
		while (count <= num * num) {

			while (map[i][j] == 0) {
				map[i][j] = count;
				count++;
				if (j + 1 < n) {
					if (map[i][j + 1] == 0) {
						j = j + 1;
					}
				}
			}

			if (i + 1 < num) {
				i = i + 1;
			}
			while (map[i][j] == 0) {
				map[i][j] = count;
				count++;
				if (i + 1 < n) {
					if (map[i + 1][j] == 0) {
						i = i + 1;
					}
				}
			}
			
			if (j > 0) {
				j = j - 1;
			}
			
			while (map[i][j] == 0) {
				map[i][j] = count;
				count++;
				if(j > 0) {
					if (map[i][j - 1] == 0) {
						j = j - 1;
					}
				}
			}

			if (i > 0) {
				i = i - 1;
			}

			while (map[i][j] == 0) {
				map[i][j] = count;
				count++;
				if (i > 0) {
					if (map[i - 1][j] == 0) {
						i = i - 1;
					}
				}
			}

			n--;
			if (map[i][j] != 0) {
				j = j + 1;
				if (map[i][j] != 0) {
					break;
				}
			}
		}

		//
		cout << "#" << t + 1 << endl;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}