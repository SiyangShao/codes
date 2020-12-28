#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n, s, t;
	cin >> n >> s >> t;
	cout << max(n - t, n - s) + 1 << "\n";
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