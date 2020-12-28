#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
int n;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
		i--;
	}
	if (n == 2) {
		cout << a[0];
		return;
	}
	int i = 0;
	for (i = 0; i < n; i++)
		if (a[i] == 0)
			break;
	if (a[(i + 1) % n] == 1)
		cout << min(i, 1 + n - i + 1);
	else {
		i = n - 1 - i;
		cout << min(n - i + 1, 1 + i);
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}