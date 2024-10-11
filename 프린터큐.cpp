#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int total;
    int n, m;
    int priority;
    int result;

    cin >> total;

    for (int i = 0; i < total; i++) {
        result = 0;
        cin >> n >> m;

        priority_queue<int> pq;
        queue<pair<int, int>> q;

        for (int j = 0; j < n; j++) {
            cin >> priority;
            q.push({ j, priority });
            pq.push(priority);
        }

        while (!q.empty()) {
            int index = q.front().first;
            int pr = q.front().second;
            q.pop();

            if (pq.top() == pr) {
                pq.pop();
                ++result;
                if (m == index) {
                    cout << result << endl;
                    break;
                }
            }

            else q.push({ index, pr });
        }
    }

    return 0;
}