#include <iostream>

using namespace std;

char field[101][101];
bool visited[101][101];
void DFS(int x, int y);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++) {
        string color;
        cin >> color;

        for (int j = 0; j < color.length(); j++) {
            field[i + 1][j + 1] = color[j];
        }
    }

    int normal = 0;
    int redgreen = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[j][i]) {
                DFS(i, j);
                normal++;
            }
        }
    }
    cout << normal << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (field[j][i] == 'G') {
                field[j][i] = 'R';
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[j][i]) {
                DFS(i, j);
                redgreen++;
            }
        }
    }

    cout << redgreen << endl;
}

void DFS(int x, int y) {
    if (visited[y][x]) {
        return;
    }

    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(field[y][x] == field[next_y][next_x] && !visited[next_y][next_x]) {
            DFS(next_x, next_y);
        }
    }
}
