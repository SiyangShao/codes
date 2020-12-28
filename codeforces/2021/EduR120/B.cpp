#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> q(n);
	for (auto &i : q) {
		cin >> i;
	}
	string s;
	cin >> s;
	unordered_map<int, int> mp;
	vector<int> z, o;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			z.emplace_back(i);
		} else {
			o.emplace_back(i);
		}
	}
	sort(z.begin(), z.end(), [&](int x, int y) { return q[x] < q[y]; });
	sort(o.begin(), o.end(), [&](int x, int y) { return q[x] < q[y]; });
	int cnt = 0;
	for (auto i : z) {
		mp[i] = ++cnt;
	}
	for (auto i : o) {
		mp[i] = ++cnt;
	}
	for (int i = 0; i < n; ++i) {
		cout << mp[i] << " ";
	}
	cout << "\n";
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