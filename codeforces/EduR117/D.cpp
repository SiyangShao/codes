#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool gcd(ll a, ll b, ll x) {
	if (a < b) {
		swap(a, b);
	}
	if (a < x && b < x) {
		return false;
	} else if (a == x || b == x) {
		return true;
	} else if (x % b == a % b) {
		return true;
	} else {
		return gcd(b, a % b, x);
	}
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