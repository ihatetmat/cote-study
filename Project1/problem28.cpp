#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
static vector<vector<edge>> A;
static vector<bool> visited;
static vector<int> m_distance;

void BFS(int index) {
	queue<int> myQueue;
	myQueue.push(index);
	visited[index] = true;

	while (!myQueue.empty()) {
		int n = myQueue.front();
		myQueue.pop();
		for (edge i : A[n]) {
			if (!visited[i.first]) {
				visited[i.first] = true;
				myQueue.push(i.first);
				m_distance[i.first] = m_distance[n] + i.second;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	A.resize(N + 1);
	
	for (int i = 0; i < N; i++) {
		int s;
		cin >> s;
		while (true) {
			int e, d;
			cin >> e;
			if (e == -1) {
				break;
			}
			cin >> d;
			A[s].push_back(edge(e, d));
		}
	}

	m_distance = vector<int>(N + 1, 0);
	visited = vector<bool>(N + 1, 0);
	BFS(1);
	int Max = 1;
	for (int i = 2; i <= N; i++) {
		if (m_distance[i] > m_distance[Max]) {
			Max = i;
		}
	}
	m_distance = vector<int>(N + 1, 0);
	visited = vector<bool>(N + 1, 0);
	BFS(Max);
	sort(m_distance.begin(), m_distance.end());
	cout << m_distance[N] << endl;
}