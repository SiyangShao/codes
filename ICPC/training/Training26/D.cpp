#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
constexpr int N = 3e5 + 7;
int n, p, cnt;
vector<int> num, ini;
unordered_map<int, int> mp;
vector<int> E[N];
inline int cal(int x) {
	int dif = p - E[x].size();
	if (dif <= 0) {
		return n - 1;
	}
	mp.clear();
	mp[x] = E[x].size();
	for (auto i : E[x]) {
		mp[i]++;
	}
	auto cnt = num.end() - lower_bound(num.begin(), num.end(), dif);
	for (auto i : mp) {
		if (ini[i.first] >= dif && ini[i.first] - i.second < dif) {
			cnt--;
		}
	}
	return cnt;
}
void solve() {
	cin >> n >> p;
	num.resize(n);
	ini.resize(n);
	for (int i = 1, u, v; i <= n; ++i) {
		cin >> u >> v;
		u--, v--;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
		num[u]++, num[v]++;
		ini[u]++, ini[v]++;
	}
	sort(num.begin(), num.end());
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += cal(i);
	}
	cout << sum / 2 << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}