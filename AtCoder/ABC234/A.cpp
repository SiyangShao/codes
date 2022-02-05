#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll f(ll x) { return x * x + 2 * x + 3; }
void solve() {
	ll x;
	cin >> x;
	cout << f(f(f(x) + x) + f(f(x)));
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