#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> p(64, 0);
inline void insert(ll x) {
	for (int i = 60; i >= 0; --i) {
		if (!(x >> ll(i)))
			continue;
		if (!p[i]) {
			p[i] = x;
			break;
		}
		x ^= p[i];
	}
}
inline bool ask(ll x) {
	for (int i = 60; i >= 0; i--)
		if (x & (1LL << i))
			x ^= p[i];
	return x == 0;
}
inline ll askmx() {
	ll ans = 0;
	for (int i = 60; i >= 0; --i) {
		if ((ans ^ p[i]) > ans) {
			ans ^= p[i];
		}
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	p.resize(64, 0);
	for (auto &i : a) {
		cin >> i;
		insert(i);
	}
	cout << askmx() << "\n";
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