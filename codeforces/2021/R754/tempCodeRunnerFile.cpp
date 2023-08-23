#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ll n, a, b, c;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		ll ans = abs(a + c - b * 2);
		cout << ans % 3 << "\n";
	}
}