#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long Min, Max;
	cin >> Min >> Max;
	vector<bool> Check(Max - Min + 1);

	for (int i = 2; i * i <= Max; i++) {
		long pow = i * i;
		long start_index = Min / pow;

		if (Min % pow != 0) {
			start_index++;
		}
		for (int j = start_index; pow * j <= Max; j++) {
			Check[(int)((j * pow) - Min)] = true;
		}
	}

	int count = 0;

	for (int i = 0; i <= Max - Min; i++) {
		if (!Check[i]) {
			count++;
		}
	}

	cout << count << endl;
}