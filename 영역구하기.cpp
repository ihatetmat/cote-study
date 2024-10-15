#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100][100] = {false};
int DFS(int x, int y);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int area = 0;
int cnt = 0;
int m, n;
vector<int> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int lx, ly, hx, hy;
        cin >> lx >> ly >> hx >> hy;
        for (int y = ly; y < hy; y++) {
            for (int x = lx; x < hx; x++) {
                visited[y][x] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                result.push_back(DFS(j, i));
                cnt = 0;
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
}

int DFS(int x, int y) {

    visited[y][x] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
        if (!visited[new_y][new_x]) {
            DFS(new_x, new_y);
        }
    }

    return cnt;
}