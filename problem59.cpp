#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> edge;
static int N, M;
static vector<long> mdistance;
static vector<edge> edges;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	mdistance.resize(N + 1);
	fill(mdistance.begin(), mdistance.end(), LONG_MAX);

	for (int i = 0; i < M; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		edges.push_back(make_tuple(start, end, time));
	}

	mdistance[1] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int start = get<0>(edges[j]);
			int end = get<1>(edges[j]);
			int time = get<2>(edges[j]);

			if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
				mdistance[end] = mdistance[start] + time;
			}
		}
	}

	bool myCycle = false;

	for (int i = 0; i < M; i++) {
		int start = get<0>(edges[i]);
		int end = get<1>(edges[i]);
		int time = get<2>(edges[i]);

		if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
			myCycle = true;
		}
	}

	if (!myCycle) {
		for (int i = 2; i <= N; i++) {
			if (mdistance[i] == LONG_MAX) {
				cout << -1 << endl;
			}
			else {
				cout << mdistance[i] << endl;
			}
		}
	}
	else {
		cout << -1 << endl;
	}
}