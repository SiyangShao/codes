#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, sum;
int a[10000010];
inline long long binpow(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
signed main() {
	cin >> n;
	for (int i = 1; i <= sqrt(n) && i < 10000010; i++) {
		a[i] = i * i;
	}
	for (int i = 2; i < 55; i++) {
		sum = 0;
		for (int j = 1; j <= sqrt(n); j++) {
			if (j <= 10000009) {
				sum += a[j];
				a[j] *= j;
			} else {
				sum += binpow(j, i);
			}
			if (sum == n) {
				cout << i + 1 << " " << j;
				return 0;
			}
			if (sum > n) {
				break;
			}
		}
	}
	cout << "impossible";
}