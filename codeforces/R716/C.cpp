#include <bits/stdc++.h>
#define int long long
using namespace std;
int ok[100010];
signed main() {
	int n;
	cin >> n;
	int ans = 1, sum = 0;
	for (int i = 1; i < n; i++) {
		if (__gcd(i, n) == 1) {
			ans *= i;
			ok[i] = 1;
			ans %= n;
		}
	}
	if (ans != 1) {
		ok[ans] = 0;
	}
	cout << count(ok + 1, ok + n, 1) << "\n";
	for (int i = 1; i < n; i++) {
		if (ok[i]) {
			cout << i << " ";
		}
	}
	// cout<<ans;
}