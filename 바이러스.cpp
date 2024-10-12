#include <iostream>
#include <vector>

using namespace std;

vector<int> v[105];
bool visited[105];
void DFS(int start);
int result = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }

    int start = 1;
    DFS(start);
    cout << result << endl;
}

void DFS(int start) {
    if (visited[start]) {
        return;
    }

    visited[start] = true;

    for (int i : v[start]) {
        if (!visited[i]) {
            result++;
            DFS(i);
        }
    }
}