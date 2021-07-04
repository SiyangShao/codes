#include <bits/stdc++.h>
using namespace std;
int N;
long long a[200010], f[200010];
const int mod = 998244353;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + N);
	for (int i = N; i >= 1; i--) {
		f[i] = 2 * f[i + 1] + a[i + 1];
		f[i] %= mod;
	}
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += a[i] * f[i];
		sum %= mod;
		sum += a[i] * a[i];
		sum %= mod;
	}
	cout << sum;
}