#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<vector<int>> A;
	vector<int> indegree;
	vector<int> selfBuild;
	A.resize(N + 1);
	indegree.resize(N + 1);
	selfBuild.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> selfBuild[i];
		while (true) {
			int temp;
			cin >> temp;

			if (temp == -1) {
				break;
			}
			A[temp].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> myQueue;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			myQueue.push(i);
		}
	}
	vector<int> result;
	result.resize(N + 1);

	while (!myQueue.empty()) {
		int now = myQueue.front();
		myQueue.pop();
		for (int node : A[now]) {
			indegree[node]--;
			result[node] = max(result[node], result[now] + selfBuild[now]);
			if (indegree[node] == 0) {
				myQueue.push(node);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << result[i] + selfBuild[i] << endl;
	}
}