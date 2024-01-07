#include <iostream>
#include <queue>

using namespace std;

struct compare {
	bool operator()(int o1, int o2) {
		int first_abs = abs(o1);
		int second_abs = abs(o2);
		if (first_abs == second_abs) {
			return o1 > o2;
		}
		else {
			return first_abs > second_abs;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, compare> myQueue;
	vector<int> result;

	for (int i = 0; i < N; i++) {
		int request;
		cin >> request;
		if (request == 0) {
			if (myQueue.empty()) {
				result.push_back(0);
			}
			else {
				result.push_back(myQueue.top());
				myQueue.pop();
			}
		}
		else {
			myQueue.push(request);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}