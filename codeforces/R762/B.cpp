#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
inline void solve() {
	ll n;
	cin >> n;
	cout << ll(pow(n, 1.0 / 2) + eps) + ll(pow(n, 1.0 / 3) + eps) -
				ll(pow(n, 1.0 / 6) + eps)
		 << "\n";
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