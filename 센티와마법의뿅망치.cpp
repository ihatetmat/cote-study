#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, h, t;
    cin >> n >> h >> t;
    priority_queue<int> pq;

    for (int i = 1; i <= n; i++) {
        int H;
        cin >> H;
        pq.push(H);
    }

    int j;
    for (j = 0; j < t; j++) {
        int top = pq.top();
        if (h > top) {
            break;
        }
        int after;
        if (top == 1) {
            after = 1;
        }
        else {
            after = top / 2;
        }
        pq.pop();
        pq.push(after);
    }

    int answer = false;
    int temp = pq.top();
    if (h > temp) {
        answer = true;
    }
    if (answer) {
        cout << "YES" << endl;
        cout << j << endl;
    }
    else {
        cout << "NO" << endl;
        cout << temp << endl;
    }
}
