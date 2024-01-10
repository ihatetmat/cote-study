#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int> plusPq;
	priority_queue<int, vector<int>, greater<int>> minusPq;
	int one = 0;
	int zero = 0;
	
	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		if (data > 1) {
			plusPq.push(data);
		} 
		else if (data < 0) {
			minusPq.push(data);
		}
		else if (data == 1) {
			one++;
		}
		else if (data == 0) {
			zero++;
		}
	}

	int sum = 0;
	
	while (plusPq.size() > 1) {
		int first = plusPq.top();
		plusPq.pop();
		int second = plusPq.top();
		plusPq.pop();
		sum = sum + first * second;
	}

	if (!plusPq.empty()) {
		sum = sum + plusPq.top();
		plusPq.pop();
	}

	while (minusPq.size() > 1) {
		int first = minusPq.top();
		minusPq.pop();
		int second = minusPq.top();
		minusPq.pop();
		sum = sum + first * second;
	}

	if (!minusPq.empty()) {
		if (zero == 0) {
			sum = sum + minusPq.top();
			minusPq.pop();
		}
	}

	sum += one;
	cout << sum << endl;
}