#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool gcd(ll a, ll b, ll x) {
	if (a < x && b < x)
		return 0;
	if (a == x || b == x)
		return 1;
	if ((a == b) || (a == 0) || (b == 0))
		return 0;
	if (a < b)
		swap(a, b);
	if ((a - x) % b == 0)
		return 1;
	if (a % b == 0)
		return x % b == 0;
	a = a % b + max(x - x % b, b);
	return gcd(a - b, b, x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll t, a, b, x;
	cin >> t;
	while (t--) {
		cin >> a >> b >> x;
		if (gcd(a, b, x)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
}