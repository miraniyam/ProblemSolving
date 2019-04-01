#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> caseMap;
vector<int> bi;
vector<int> bj;
vector<int> vi;
vector<int> vj;
int n = 0, m = 0;

void spreadVirus(int i, int j) {
	int upi = i - 1;
	if (upi >= 0) {
		if (caseMap[upi][j] == 0) {
			caseMap[upi][j] = 2;
			spreadVirus(upi, j);
		}
	}

	int downi = i + 1;
	if (downi < n) {
		if (caseMap[downi][j] == 0) {
			caseMap[downi][j] = 2;
			spreadVirus(downi, j);
		}
	}

	int leftj = j - 1;
	if (leftj >= 0) {
		if (caseMap[i][leftj] == 0) {
			caseMap[i][leftj] = 2;
			spreadVirus(i, leftj);
		}
	}

	int rightj = j + 1;
	if (rightj < m) {
		if (caseMap[i][rightj] == 0) {
			caseMap[i][rightj] = 2;
			spreadVirus(i, rightj);
		}
	}
}

int main() {

	cin >> n;
	cin >> m;

	int howManyZero = 0;
	vector<vector<int>> base;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			int tt;
			cin >> tt;
			temp.push_back(tt);
			if (tt == 0) {
				bi.push_back(i);
				bj.push_back(j);
				howManyZero++;
			}
			if (tt == 2) {
				vi.push_back(i);
				vj.push_back(j);
			}
		}
		base.push_back(temp);
	}
	
	int max = 0;

	caseMap.resize((int)base.size());

	for (int i = 0; i < bi.size() - 2; i++) {
		for (int j = i + 1; j < bi.size() - 1; j++) {
			for (int k = j + 1; k < bi.size(); k++) {
				
				int zero = 0;
				copy(base.begin(), base.end(), caseMap.begin());
				// 벽 세우기
				caseMap[bi[i]][bj[i]] = 1;
				caseMap[bi[j]][bj[j]] = 1;
				caseMap[bi[k]][bj[k]] = 1;

				// 바이러스 퍼뜨리기 -> 재귀문 써야할듯..
				for (int v = 0; v < vi.size(); v++) {
					spreadVirus(vi[v], vj[v]);
				}

				// 안전 구역 카운팅
				for (int ci = 0; ci < n; ci++) {
					for (int cj = 0; cj < m; cj++) {
						if (caseMap[ci][cj] == 0) {
							zero++;
						}
					}
				}

				if (max < zero) {
					max = zero;
				}
			}
		}
	}

	cout << max;

	return 0;
}