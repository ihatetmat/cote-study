#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int field[25][25];
bool visited[25][25] = {false};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void DFS(int x, int y);
int result = 0;
int n;
int cnt = 0;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < input.length(); j++) {
            if (input[j] == '1') {
                field[i][j] = 1;
            }
            else {
                field[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (field[j][i] != 0 && !visited[j][i]) {
                cnt++;
                DFS(i, j);
                v.push_back(cnt);
                cnt = 0;
                result++;
            }
        }
    }

    cout << result << endl;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

void DFS(int x, int y) {
    if(visited[y][x]) {
        return;
    }

    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (!visited[next_y][next_x] && field[next_y][next_x] == field[y][x]) {
            if (next_x > n && next_x <= 0 && next_y <= 0 && next_y > n) continue;
            cnt++;
            DFS(next_x, next_y);
        }
    }
}