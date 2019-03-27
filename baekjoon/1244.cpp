#include <iostream>
using namespace std;

int main() {

	int n = 0;
	cin >> n;

	int* bolb = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> bolb[i];
	}
	
	int student = 0;
	cin >> student;

	int* stuGen = new int[n];
	int* stuNum = new int[n];
	for (int i = 0; i < student; i++) {
		cin >> stuGen[i];
		cin >> stuNum[i];
	}

	for (int i = 0; i < student; i++) {
		int base = stuNum[i];
		if (stuGen[i] == 1) {
			// 남학생
			int t = 1;
			while (base*t-1 < n) {
				bolb[base*t-1] = !bolb[base*t-1];
				t++;
			}
		}
		else {
			// 여학생
			int left = base - 2;
			int right = base;

			int begin = 0;
			int end = 0;

			bool flag = false;
			while (left >= 0 && right < n) {
				if (bolb[left] == bolb[right]) {
					begin = left;
					end = right;
					flag = true;
				}
				else {
					break;
				}
				left = left - 1;
				right = right + 1;
			}
			if (!flag) {
				bolb[base - 1] = !bolb[base - 1];
			}
			else {
				for (int w = begin; w <= end; w++) {
					bolb[w] = !bolb[w];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << bolb[i];
		if ((i + 1) % 20 == 0) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}