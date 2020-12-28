#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll ans, res, n;
	cin >> n >> ans;
	for (int i = 1; i < n; ++i) {
		cin >> res;
		ans ^= res;
	}
	cout << ans;
}