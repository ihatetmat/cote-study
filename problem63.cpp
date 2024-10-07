#include <iostream>
#include <limits.h>

using namespace std;

static int N, M;
static long mdistance[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				mdistance[i][j] = 0;
			}
			else {
				mdistance[i][j] = 10000001;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		mdistance[s][e] = 1;
		mdistance[e][s] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (mdistance[i][j] > mdistance[i][k] + mdistance[k][j]) {
					mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
				}
			}
		}
	}

	int MIN = INT_MAX;
	int Answer = -1;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			temp += mdistance[i][j];
		}
		if (MIN > temp) {
			MIN = temp;
			Answer = i;
		}
	}

	cout << Answer << endl;
}