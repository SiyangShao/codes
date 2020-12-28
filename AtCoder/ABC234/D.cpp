#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
void solve() {
	ll n, k;
	cin >> n >> k;
	priority_queue<ll, vector<ll>, greater<ll>> Q;
	for (int i = 1, u; i <= k; ++i) {
		cin >> u;
		Q.push(u);
	}
	cout << Q.top() << "\n";
	for (int i = k + 1, u; i <= n; ++i) {
		cin >> u;
		if (u > Q.top()) {
			Q.pop();
			Q.push(u);
		}
		cout << Q.top() << "\n";
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