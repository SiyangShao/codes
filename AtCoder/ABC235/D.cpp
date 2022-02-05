#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n, a;
	unordered_map<ll, ll> mp;
	cin >> a >> n;
	queue<ll> Q;
	mp[1] = 1;
	Q.push(1ll);
	while (!Q.empty()) {
		auto u = Q.front();
		Q.pop();
		if (u == n) {
			cout << mp[n] - 1 << "\n";
			return;
		}
		if (u >= 10 && u % 10 != 0) {
			auto nxt = u % 10, pre = u / 10;
			auto tmp = pre;
			while (tmp) {
				nxt *= 10;
				tmp /= 10;
			}
			auto v = pre + nxt;
			if (mp.find(v) == mp.end()) {
				mp[v] = mp[u] + 1;
				Q.push(v);
				if (v == n) {
					cout << mp[n] - 1 << "\n";
					return;
				}
			}
		}
		if (u * a <= n*10 && mp.find(u * a) == mp.end()) {
			mp[u * a] = mp[u] + 1;
			if (u * a == n) {
				cout << mp[n] - 1 << "\n";
				return;
			}
			Q.push(u * a);
		}
	}
	cout << "-1\n";
}
ll judge(ll u) {
	if (u >= 10 && u % 10 != 0) {
		auto nxt = u % 10, pre = u / 10;
		auto tmp = pre;
		while (tmp) {
			nxt *= 10;
			tmp /= 10;
		}
		auto v = pre + nxt;
		return v;
	} else {
		return -1;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
		// ll tmp;
		// while (cin >> tmp) {
		// 	cout << judge(tmp) << "\n";
		// }
	}
}