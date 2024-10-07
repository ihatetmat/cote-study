#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;
static vector<int> check;
static vector<bool> visited;
static bool isEven;

void DFS(int node) {
	visited[node] = true;

	for (int i : A[node]) {
		if (!visited[i]) {
			check[i] = (check[node] + 1) % 2;
			DFS(i);
		}
		else if (check[node] == check[i]) {
			isEven = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int V, E;
		cin >> V >> E;
		A.resize(V + 1);
		visited.resize(V + 1);
		check.resize(V + 1);
		isEven = true;

		for (int j = 0; j < E; j++) {
			int S, E;
			cin >> S >> E;
			A[S].push_back(E);
			A[E].push_back(S);
		}

		for (int i = 1; i <= V; i++) {
			if (isEven) {
				DFS(i);
			}
			else {
				break;
			}
		}

		if (isEven) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		for (int i = 0; i <= V; i++) {
			A[i].clear();
			visited[i] = false;
			check[i] = 0;
		}
	}
}