#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

void DFS(int node) {
	cout << node << ' ';
	visited[node] = true;
	
	for (int i : A[node]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int node) {
	queue<int> myQueue;
	myQueue.push(node);
	visited[node] = true;
	while (!myQueue.empty()) {
		int n = myQueue.front();
		myQueue.pop();
		cout << n << ' ';
		for (int i : A[n]) {
			if (!visited[i]) {
				myQueue.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, Start;
	cin >> N >> M >> Start;
	A.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	for (int i = 1; i <= N; i++) {
		sort(A[i].begin(), A[i].end());
	}

	visited = vector<bool>(N + 1, false);

	DFS(Start);
	cout << endl;
	visited = vector<bool>(N + 1, false);
	BFS(Start);
	cout << endl;
}