#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, fa, cnt;
vector<vector<ll>> E;
vector<ll> in;
map<int, pair<int, int>> mp;
map<pair<int, int>, int> mp2;
void dfs(int u, int fa) {
	if (cnt % 2 == 0) {
		mp2[{u, fa}] = 2;
		mp2[{fa, u}] = 2;
	} else {
		mp2[{u, fa}] = 3;
		mp2[{fa, u}] = 3;
	}
	cnt++;
	for (auto i : E[u]) {
		if (i == fa) {
			continue;
		}
		dfs(i, u);
	}
}
void solve() {
	cin >> n;
	E.clear(), in.clear(), mp.clear(), mp2.clear();
	E.resize(n);
	in.resize(n);
	cnt = 0;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		u--, v--;
		mp[i] = {u, v};
		E[u].emplace_back(v);
		E[v].emplace_back(u);
		in[u]++, in[v]++;
	}
	for (int i = 0; i < n; ++i) {
		if (in[i] > 2) {
			cout << "-1\n";
			return;
		}
		if (in[i] == 1) {
			fa = i;
		}
	}
	dfs(fa, -1);
	for (int i = 1; i < n; ++i) {
		cout << mp2[mp[i]] << " ";
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