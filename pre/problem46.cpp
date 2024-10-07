#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static vector<vector<int>> A;
static vector<int> answer;
static vector<int> visited;

void BFS(int node) {
	queue<int> myQueue;
	myQueue.push(node);
	visited[node]++;

	while (!myQueue.empty()) {
		int n = myQueue.front();
		myQueue.pop();
		for (int i : A[n]) {
			if (visited[i] == -1) {
				visited[i] = visited[n] + 1;
				myQueue.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N, M, K, X;
	cin >> N >> M >> K >> X;
	A.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}

	visited.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		visited[i] = -1;
	}

	BFS(X);
	
	for (int i = 0; i <= N; i++) {
		if (visited[i] == K) {
			answer.push_back(i);
		}
	}

	if (answer.empty()) {
		cout << -1 << endl;
	}
	else {
		sort(answer.begin(), answer.end());
		for (int temp : answer) {
			cout << temp << endl;
		}
	}
}