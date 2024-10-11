#include <iostream>
#include <vector>

using namespace std;

int main() {
    int result = 0;
    int n;
    int king;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> king;

    vector<int> v(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }

    while (true) {
        int max = 0;
        int index = 0;

        for (int i = 0; i < n - 1; i++) {
            if (max < v[i]) {
                max = v[i];
                index = i;
            }
        }
        if (king > max) {
            cout << result << "\n";
            break;
        }
        king++;
        v[index]--;
        result++;
    }
}