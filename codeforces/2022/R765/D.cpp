#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void solve() {
	int n, k;
	cin >> n >> k;
	int t = ceil(log2(k));
	map<int, int> idx;
	map<int, vector<int>> mp;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		mp[x >> t].push_back(x);
		idx[x] = i;
	}
	if (k == 0) {
		cout << n << '\n';
		for (int i = 1; i <= n; i++)
			cout << i << " ";
		cout << '\n';
		return;
	}
	vector<int> ans;
	auto check = [&](vector<int> v) {
		int tmp = 0;
		unordered_set<int> s;
		for (int i = 30; i >= 0; i--) {
			s.clear();
			for (auto it : v)
				s.insert(it >> i);

			int c = tmp * 2 + 1;
			tmp *= 2;

			for (auto it : s)
				if (s.find(c ^ it) != s.end()) {
					tmp++;
					break;
				}
		}
		if (tmp >= k) {
			for (auto it : s)
				if (s.find(tmp ^ it) != s.end()) {
					ans.push_back(idx[it]);
					ans.push_back(idx[tmp ^ it]);
					return;
				}
		}
		ans.push_back(idx[*s.begin()]);
	};

	for (auto [_, it] : mp)
		check(it);
	if (ans.size() < 2) {
		cout << -1 << '\n';
		return;
	}
	cout << ans.size() << '\n';
	for (auto it : ans)
		cout << it << " ";
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}