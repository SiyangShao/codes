#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
void solve() {
	ll k;
	cin >> k;
	string ans = "";
	while (k) {
		if (k & 1) {
			ans.push_back('2');
		} else {
			ans.push_back('0');
		}
		k >>= 1;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
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