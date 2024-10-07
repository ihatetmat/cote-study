#include <iostream>

using namespace std;

int main() {
	int N;
	int start_index = 1;
	int end_index = 1;
	int sum = 1;
	int count = 1;
	cin >> N;
	while (end_index != N) {
		if (sum == N) {
			count++;
			end_index++;
			sum += end_index;
		}
		else if (sum > N) {
			sum -= start_index;
			start_index++;
		}
		else if (sum < N) {
			end_index++;
			sum += end_index;
		}
	}
	cout << count << endl;
}