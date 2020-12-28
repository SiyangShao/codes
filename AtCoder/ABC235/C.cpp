#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n, q;
	unordered_map<int, vector<int>> mp;
	cin >> n >> q;
	for (int i = 1, tmp; i <= n; ++i) {
		cin >> tmp;
		mp[tmp].emplace_back(i);
	}
	int x, k;
	while (q--) {
		cin >> x >> k;
		if (mp[x].size() < k) {
			cout << "-1\n";
		} else {
			cout << mp[x][k - 1] << "\n";
		}
	}
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