#include <iostream>

using namespace std;

int field[51][51] = {0};
int result = 0;
void DFS(int x, int y, int m, int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m, n, k;
        cin >> m >> n >> k;

        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (field[r][c] == 1) {
                    DFS(c, r, m, n);
                    result++;
                }
            }
        }
        cout << result << endl;
        result = 0;
    }
}

void DFS(int x, int y, int m, int n) {
    for (int i = 0; i < 4; i++) {
        if (x >= 0 && x < m && y >= 0 && y < n && field[y][x] == 1) {
            field[y][x] = 0;
            DFS(x - 1, y, m, n);
            DFS(x + 1, y, m, n);
            DFS(x, y - 1, m, n);
            DFS(x, y + 1, m, n);
        }
    }
    return;
}