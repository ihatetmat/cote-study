#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int> gift;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            if (gift.empty()) {
                v.push_back(-1);
            }
            else {
                v.push_back(gift.top());
                gift.pop();
            }
        }
        else {
            for (int j = 0; j < a; j++) {
                int value;
                cin >> value;
                gift.push(value);
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}