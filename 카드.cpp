#include <iostream>
#include <deque>

using namespace std;

void print(deque<int> dq) {
    for (int i=0; i<dq.size(); i++) {
        cout<<dq[i]<<' ';
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    deque<int> dq;
    dq.push_back(n);

    for(int i = n - 1; i > 0; i--) {
        dq.push_front(i);
        for(int j = 0; j < i; j++) {
            int temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
        }
    }

    print(dq);

    return 0;
}