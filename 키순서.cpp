#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, total;
vector<int> smaller[501]; // 자신보다 작은 학생
vector<int> taller[501]; // 자신보다 큰 학생
bool visited[501];
void DFS(vector<int> v[], int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int small, tall;
        cin >> small >> tall;
        smaller[tall].push_back(small);
        taller[small].push_back(tall);
    }

    int result = 0;
    for(int i = 1; i <= n; i++){
        total = 0;
        memset(visited, 0, sizeof(visited));
        DFS(smaller, i);
        memset(visited, 0, sizeof(visited));
        DFS(taller, i);
        if(total == n - 1) {
            result++;
        }
    }

    cout << result << endl;
    return 0;
}

void DFS(vector<int> v[], int start){

    visited[start] = true;

    for (int i : v[start]){
        if(!visited[i]){
            visited[i] = true;
            total++;
            DFS(v, i);
        }
    }
}