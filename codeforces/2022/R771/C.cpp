#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll cnt = 0, lst =0 ;
	for (auto &i : a) {
		cin >> i;
	}
	for (int i = 0; i < n; ++i) {
		if (lst == i) {
			cnt++;
		}
		lst = max(lst, a[i]);
	}
	cout << cnt << "\n";
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