#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		priority_queue<int, vector<int>, greater<int>> q;
		cin >> n;
		int ans = 0, add = 0;
		for (int i = 1, tmp; i <= n; ++i) {
			cin >> tmp;
			q.push(tmp);
		}
		int now = 0;
		if (q.size() == 1) {
			cout << q.top() << "\n";
		} else {
			while (!q.empty()) {
			}
		}
	}
}