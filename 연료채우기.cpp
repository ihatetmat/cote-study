#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, L, P;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    cin >> L >> P;

    sort(v.begin(), v.end());
    priority_queue<int> pq;

    int idx = 0, remain = P, result = 0;
    while (remain < L) {
        while (idx < n && v[idx].first <= remain) {
            pq.push(v[idx++].second);
        }
        if (pq.empty()) {
            result = -1;
            break;
        }
        remain += pq.top();
        pq.pop();
        result++;
    }
    cout << result << endl;
    return 0;
}