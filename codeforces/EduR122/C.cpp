#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll hc, dc, hm, dm, k, w, a;
	cin >> hc >> dc >> hm >> dm >> k >> w >> a;
	for (ll i = 0; i <= k; i++) {
		ll t1 = (ll)ceil(hm * 1.0 / (dc + (k - i) * w));
		ll t2 = (ll)ceil((hc + i * a) * 1.0 / dm);
		if (t1 <= t2) {
			puts("YES");
			return;
		}
	}
	puts("NO");
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