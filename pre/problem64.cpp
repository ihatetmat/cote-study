#include <iostream>
#include <queue>

using namespace std;

static vector<int> parent;
typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;

int find(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}

void munion(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	parent.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		pq.push(Edge{ s, e, v });
	}

	int useEdge = 0;
	int result = 0;

	while (useEdge < N - 1) {
		Edge now = pq.top();
		pq.pop();

		if (find(now.s) != find(now.e)) {
			munion(now.s, now.e);
			result += now.v;
			useEdge++;
		}
	}

	cout << result;
}