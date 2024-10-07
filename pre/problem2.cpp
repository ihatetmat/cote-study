#include <iostream>

using namespace std;

int main() {
	int N = 0;
	int A[1000];
	long sum = 0;
	long max = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		sum += A[i];
		if (A[i] > max) {
			max = A[i];
		}
	}
	double result = sum * 100.0 / max / N;

	cout << result;
}