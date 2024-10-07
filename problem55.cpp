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

	vector<vector<pair<int, int>>> A;
	vector<vector<pair<int, int>>> reverseA;
	vector<int> indegree;
	
	A.resize(N + 1);
	reverseA.resize(N + 1);
	indegree.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int S, E, V;
		cin >> S >> E >> V;
		A[S].push_back(make_pair(E, V));
		reverseA[E].push_back(make_pair(S, V));
		indegree[E]++;
	}

	int startDosi, endDosi;
	cin >> startDosi >> endDosi;
	queue<int> myQueue;
	myQueue.push(startDosi);
	vector<int> result;
	result.resize(N + 1);

	while (!myQueue.empty()) {
		int now = myQueue.front();
		myQueue.pop();

		for (pair<int, int> next : A[now]) {
			indegree[next.first]--;
			result[next.first] = max(result[next.first], result[now] + next.second);
			if (indegree[next.first] == 0) {
				myQueue.push(next.first);
			}
		}
	}

	int resultCount = 0;
	vector<bool> visited;
	visited.resize(N + 1);
	queue<int> myQueue2;
	myQueue2.push(endDosi);
	visited[endDosi] = true;

	while (!myQueue2.empty()) {
		int now = myQueue2.front();
		myQueue2.pop();
		
		for (pair<int, int> next : reverseA[now]) {
			if (result[next.first] + next.second == result[now]) {
				resultCount++;
				if (visited[next.first] == false) {
					visited[next.first] = true;
					myQueue2.push(next.first);
				}
			}
		}
	}

	cout << result[endDosi] << endl;
	cout << resultCount << endl;
}