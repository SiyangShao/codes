#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n, now, nxt, flag = true;
	cin >> n >> now;
	for (int i = 1; i < n; ++i) {
		cin >> nxt;
		if (flag && nxt > now) {
			now = nxt;
		} else {
			flag = false;
		}
	}
	cout << now << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}