#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	vector<int> A(t);

	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		int result = a * b / gcd(a, b);
		A[i] = result;
	}

	for (int i = 0; i < t; i++) {
		cout << A[i] << endl;
	}
}