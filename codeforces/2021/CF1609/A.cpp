#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, a[16], b[16];
void judge(int i) {
	b[i] = 0;
	while (a[i] % 2 == 0) {
		b[i]++;
		a[i] /= 2;
	}
}
long long binpow(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		ll sum = 0, ans = 0, now = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			judge(i);
			sum += b[i];
			now = max(now, a[i]);
			ans += a[i];
		}
		ans -= now;
		ans += now * binpow(2, sum);
		cout << ans << "\n";
	}
}