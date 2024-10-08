#include <iostream>
#include <deque>

using namespace std;

int n;
deque<pair<int, int>> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    deque<pair<int, int>> dq;
    cin >> n;
    for (int i = 0; i < n;i++) {
        int tmp;
        cin >> tmp;
        dq.push_back(make_pair(tmp, i+1));
    }

    while (true) {
        int cnt = dq.front().first;
        cout << dq.front().second << " ";
        dq.pop_front();
        if (dq.empty())
            break;
        if (cnt > 0) {
            for (int i = 0; i < cnt - 1;i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for (int i = cnt; i < 0;i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}