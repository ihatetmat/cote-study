#include <iostream>
#include <cstring>

using namespace std;

int max_n = 101;
int n;
int field[101][101];
bool visited[101][101] = {false};
void DFS(int x, int y, int height);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int h = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> field[i][j];
            h = max(h, field[i][j]);
        }
    }

    int result = 1;

    for (int k = 1; k <= h; k++) {
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (field[j][i] > k && !visited[j][i]) {
                    DFS(i, j, k);
                    cnt++;
                }
            }
        }
        result = max(result, cnt);
    }
    cout << result << endl;
    return 0;
}

void DFS(int x, int y, int height) {

    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= n) {
            if (!visited[new_y][new_x] && field[new_y][new_x] > height) {
                DFS(new_x, new_y, height);
            }
        }
    }
}