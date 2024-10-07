#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> myQueue;

	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		myQueue.push(data);
	}

	int first = 0;
	int second = 0;
	int sum = 0;

	while (myQueue.size() != 1) {
		first = myQueue.top();
		myQueue.pop();
		second = myQueue.top();
		myQueue.pop();
		sum += first + second;
		myQueue.push(first + second);
	}

	cout << sum << endl;
}