#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll t, n, k;
ll qpow() {
	ll sum = 0, base = 1;
	while (k) {
		if (k % 2 == 0) {
			k /= 2;
			base *= n;
			base %= mod;
		} else {
			sum += base;
			sum %= mod;
			base *= n;
			base %= mod;
			k /= 2;
		}
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << qpow() << "\n";
	}
}