#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int cnt = 0;
vector<int> v[101];
bool visited[101] = {false};
int DFS(int start, int target, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }

    int result = DFS(a, b, 0);

    cout << result << endl;

    return 0;
}

int DFS(int start, int target, int depth) {
    if(start == target) {
        return depth;
    }

    visited[start] = true;

    int result = INT_MAX;
    if (v[start].size() == 0) return -1;
    for (int family : v[start]) {
        if (!visited[family]) {
            int intermediate = DFS(family, target, depth + 1);
            if (intermediate != -1) {
                result = min(result, intermediate);
            }
        }
    }

    if (result == INT_MAX) {
        return -1;
    }
    else {
        return result;
    }
}