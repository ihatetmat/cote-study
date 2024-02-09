#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
static int N, M;
static vector<vector<edge>> mlist;
static vector<int> dist;
static vector<bool> visited;

int dijkstra(int start, int end) {
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		edge nowNode = pq.top();
		pq.pop();
		int now = nowNode.second;

		if (!visited[now]) {
			visited[now] = true;

			for (edge next : mlist[now]) {
				if (!visited[next.first] && dist[now] + next.second < dist[next.first]) {
					dist[next.first] = dist[now] + next.second;
					pq.push(make_pair(dist[next.first], next.first));
				}
			}
		}
	}

	return dist[end];
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	dist.resize(N + 1);
	fill(dist.begin(), dist.end(), INT_MAX);
	visited.resize(N + 1);
	fill(visited.begin(), visited.end(), false);
	mlist.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		mlist[start].push_back(make_pair(end, weight));
	}

	int startIndex, endIndex;
	cin >> startIndex >> endIndex;

	cout << dijkstra(startIndex, endIndex) << endl;
}