#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

int n, num[2], WW, BB, EMPTY, WB, BW;

inline void add(char c) {
	if (c == 'W')
		num[0]++;
	else if (c == 'B')
		num[1]++;
}
int qpow(ll a, int b) {
	int r = 1;
	for (; b; b >>= 1, a = a * a % mod)
		if (b & 1)
			r = a * r % mod;
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string s;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		if (s == "WW")
			WW = 1;
		else if (s == "BB")
			BB = 1;
		else if (s == "??")
			EMPTY++;
		else if (s[0] == 'W' || s[1] == 'B')
			WB = 1;
		else if (s[0] == 'B' || s[1] == 'W')
			BW = 1;
		add(s[0]), add(s[1]);
	}
	if (num[0] > n || num[1] > n)
		return puts("0");
	ll ans = 1;
	int f = WW + BB;
	for (int i = 1; i <= n - num[0]; ++i) {
		ans = ans * (2 * n - num[0] - num[1] - i + 1) % mod * qpow(i, mod - 2) %
			  mod;
	}
	// cout<<ans<<'\n';
	if (f == 0) {
		if (WB + BW == 2)
			ans -= qpow(2, EMPTY);
		else if (WB + BW == 1)
			ans = ans - qpow(2, EMPTY) + 1;
		else
			ans = ans - qpow(2, EMPTY) + 2;
		if (ans < 0)
			ans += mod;
	}
	cout << ans << '\n';
	return 0;
}
