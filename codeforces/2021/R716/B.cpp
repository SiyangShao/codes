#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int t, n, k;
long long binpow(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) {
			res = res * a;
			res %= mod;
		}
		a = a * a;
        a%=mod;
		b >>= 1;
	}
	return res%mod;
}
signed main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
        cout<<binpow(n,k)<<"\n";
	}
}