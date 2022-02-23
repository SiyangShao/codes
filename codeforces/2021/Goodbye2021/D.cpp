#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
int n, x;
vector<int> a;
void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
	}
	cin >> x;
	int dif = a[0] - x;
	bool nstart = false;
	int cnt = 0;
	for (int i = 1; i < n; ++i) {
		if (nstart) {
			dif = a[i] - x;
			nstart = false;
		} else if (a[i] >= x - dif) {
			dif = min(dif + a[i] - x, a[i] - x);
		} else {
			nstart = true;
			cnt++;
		}
	}
	cout << n - cnt << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}