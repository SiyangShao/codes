#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int qpow(int x, int k) {
	int res = 1;
	while (k) {
		if (k & 1) {
			res *= x;
			res %= mod;
		}
		x *= x;
		x %= mod;
		k >>= 1;
	}
	return res;
}
signed main() {
	int k;
	cin >> k;
    int ans = (1LL<<k)-2;
    ans = qpow(4,ans);
    ans *= 6;
    ans %= mod;
	cout << ans;
}