#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ll t, n, a[70];
	ll qpow[70];
	qpow[0] = 1;
	for (int i = 1; i <= 60; ++i) {
		qpow[i] = 2 * qpow[i - 1];
	}
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int zero = 0, one = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] == 0) {
				zero++;
			} else if (a[i] == 1) {
				one++;
			}
		}
		cout << qpow[zero] * one << "\n";
	}
}