#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> A;
	vector<int> indegree;
	A.resize(N + 1);
	indegree.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
		indegree[E]++;
	}
	queue<int> myQueue;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			myQueue.push(i);
		}
	}

	while (!myQueue.empty()) {
		int now = myQueue.front();
		myQueue.pop();
		cout << now << ' ';
		
		for (int next : A[now]) {
			indegree[next]--;
			if (indegree[next] == 0) {
				myQueue.push(next);
			}
		}
	}
}