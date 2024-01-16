#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> A;
static vector<int> answer;
static vector<bool> visited;

void BFS(int index) {
	queue<int> myQueue;
	myQueue.push(index);
	visited[index] = true;

	while (!myQueue.empty()) {
		int n = myQueue.front();
		myQueue.pop();

		for (int i : A[n]) {
			if (visited[i] == false) {
				answer[i]++;
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

	long N, M;
	cin >> N >> M;
	A.resize(N + 1);
	answer.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}

	visited.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		fill(visited.begin(), visited.end(), false);
		BFS(i);
	}

	int maxVal = 0;
	for (int i = 0; i <= N; i++) {
		if (maxVal < answer[i]) {
			maxVal = answer[i];
		}
	}

	for (int i = 0; i <= N; i++) {
		if (answer[i] == maxVal) {
			cout << i << ' ';
		}
	}
}