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

	// 0 : ������ �޽�
	// 1 : ���׽�Ʈ or �޽�
	// 2 : � or �޽�
	// 3 : � or ���׽�Ʈ or �޽�
	// �������� ��� �ϰų� ���׽�Ʈ�� �������� �ʴ´�

	// ������ ����� ���� ��� ���캻��
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