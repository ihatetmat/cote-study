#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N;
static vector<int> answer;
static vector<bool> visited;
static vector<vector<int>> tree;

void BFS(int number) {
	queue<int> myQueue;
	myQueue.push(number);
	visited[number];

	while (!myQueue.empty()) {
		int parent = myQueue.front();
		myQueue.pop();

		for (int child : tree[parent]) {
			if (!visited[child]) {
				visited[child] = true;
				answer[child] = parent;
				myQueue.push(child);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	visited.resize(N + 1);
	answer.resize(N + 1);
	tree.resize(N + 1);

	for (int i = 1; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	BFS(1);

	for (int i = 2; i <= N; i++) {
		cout << answer[i] << endl;
	}
}