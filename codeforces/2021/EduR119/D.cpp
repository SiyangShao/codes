#include <bits/stdc++.h>
using namespace std;
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
int n;
vector<int> a;
inline bool read() {
	if (!(cin >> n))
		return false;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
	}
	return true;
}
bool p(int val, int c1, int c2, int c3) {
	for (int cur1 = 0; cur1 <= c1; cur1++) {
		for (int cur2 = 0; cur2 <= c2; cur2++) {
			if (cur1 + 2 * cur2 > val)
				continue;
			if ((val - cur1 - 2 * cur2) % 3 != 0)
				continue;
			if ((val - cur1 - 2 * cur2) / 3 <= c3)
				return true;
		}
	}
	return false;
}

bool possible(int c1, int c2, int c3) {
	for (auto v : a) {
		if (!p(v, c1, c2, c3))
			return false;
	}
	return true;
}

inline void solve() {
	int m = *max_element(a.begin(), a.end());
	int ans = int(1e9);

	const int MAG = 3;
	for (int c1 = 0; c1 <= 3; ++c1) {
		for (int c2 = 0; c2 <= 3; ++c2) {
			int c3 = max(0, (m - c1 - 2 * c2 + 2) / 3);
			if (possible(c1, c2, c3))
				ans = min(ans, c1 + c2 + c3);
		}
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		read();
		solve();
	}
}