#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, c, n;
signed main() {
	cin >> n;
	int num = 1;
	int ans = 0x7f7f7f7f;
	while (num <= n) {
		if (num <= n) {
			ans = min(ans, b + n / num + n % num);
		}
		num *= 2;
		b++;
	}
	// cout << ans % 998244353;
    cout<<ans;
}