#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	priority_queue<int, vector<int>, greater<>> Q;
	for (auto &i : a) {
		cin >> i;
		Q.push(i);
	}
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		if (a[i] == Q.top()) {
			Q.pop();
		} else {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}