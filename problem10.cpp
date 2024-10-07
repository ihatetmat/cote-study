#include <iostream>
#include <deque>

using namespace std;
typedef pair<int, int> Node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	deque<Node> mydeque;

	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		while (mydeque.size() && mydeque.back().first > now) {
			mydeque.pop_back();
		}
		mydeque.push_back(Node(now, i));
		if (mydeque.front().second <= i - L) {  // second는 Node 타입의 두번째변수를 나타내는 거임
			mydeque.pop_front();
		}
		cout << mydeque.front().first << ' ';
	}
}