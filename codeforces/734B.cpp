#include <iostream>
using namespace std;

int main() {

	int input[4] = { 0, };
	for (int i = 0; i < 4; i++) {
		cin >> input[i];
	}

	int sum = 0;
	while (1) {
		if (input[0] == 0) {
			// 32 Ȥ�� 256 ���� �� ����
			break;
		}
		else {
			if (input[2] != 0 && input[3] != 0) {
				//256 ����� ����
				input[0]--;
				input[2]--;
				input[3]--;
				sum = sum + 256;
			}
			else {
				if (input[1] != 0) {
					// 32 ����� ����
					input[0]--;
					input[1]--;
					sum = sum + 32;
				}
				else {
					break;
				}
			}
		}
		
	}
	cout << sum;
	return 0;
}