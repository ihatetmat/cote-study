#include <iostream>

using namespace std;

int main() {
	string numbers;
	int sum = 0;
	int N;

	cin >> N;
	cin >> numbers;

	for (int i = 0; i < numbers.length(); i++) {
		sum += numbers[i] - '0';
	}
	cout << sum << "\n";
}