#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, b % a);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	long result = gcd(a, b);

	for (int i = 0; i < result; i++) {
		cout << 1;
	}
}