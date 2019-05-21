#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a[100001];
int visited[100001];

class Node {
public:
	int vertex;
	int count = 0;
	Node(int v, int c) {
		this->vertex = v;
		this->count = c;
	}
};

int main() {

	vector<vector<int>> table;

	// input 받기
	int n, m;
	cin >> n >> m;

	table.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for(int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		if (y == 1) {
			table[y - 1].push_back(x - 1);
		}
		else {
			table[x - 1].push_back(y - 1);
			if (x != 1) {
				table[y - 1].push_back(x - 1);
			}
		}
	}

	queue<Node*> queue;
	Node* root = new Node(0, 0);
	queue.push(root);

	int answer = 0;

	while (queue.size() != 0) {
		root = queue.front();
		int v = root->vertex;
		visited[v] = 1;
		queue.pop();

		if (a[v] == 1) {
			root->count++;
			if (root->count > m) {
				continue;
			}
		}
		else {
			// 중간에 고양이가 없으면 다시 0으로 초기화
			root->count = 0;
		}

		bool flag = false;
		for (int i = 0; i < table[v].size(); i++) {
			if (visited[table[v][i]] == 0) {
				flag = true;
				queue.push(new Node(table[v][i], root->count));
			}
		}

		if (!flag) {
			// 새로 넣은 노드 없음
			// pop한 노드가 leaf node = restaurant 임
			answer++;
		}
	}

	cout << answer;

	return 0;
}