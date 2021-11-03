#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (int i = 0, tmp; i < n; ++i) {
			cin >> a[i];
		}
		// for (auto i : a) {
		// 	cout << i << " ";
		// }
		// puts("");
		sort(a.begin(), a.end());
		bool flag = false;
		ll tire = 0, ans = -INF;
		for (auto i : a) {
			ans = max(ans, i - tire);
			tire += (i - tire);
		}
		cout << ans << "\n";
	}
}