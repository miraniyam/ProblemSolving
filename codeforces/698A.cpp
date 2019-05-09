#include <iostream>
#include <vector>
using namespace std;
int a[101];

int main() {
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 0 : 무조건 휴식
	// 1 : 콘테스트 or 휴식
	// 2 : 운동 or 휴식
	// 3 : 운동 or 콘테스트 or 휴식
	// 연속으로 운동을 하거나 콘테스트에 참여하지 않는다

	// 가능한 경우의 수를 모두 살펴본다
	int answer = 0;

	int temp = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			answer++;
			temp = 0;
		}
		else {
			if (temp != -1) {
				if (temp == a[i] && a[i] != 3) {
					answer++;
					temp = 0;
				}
				else {
					if (a[i] == 3) {
						if (temp == 1) {
							temp = 2;
						}
						else if (temp == 2) {
							temp = 1;
						}
						else {
							temp = 3;
						}
					}
					else if (a[i] == 2) {
						temp = 2;
					}
					else if (a[i] == 1) {
						temp = 1;
					}
				}
			}
			else {
				temp = a[i];
			}
		}
	}

	cout << answer << endl;

	return 0;
}