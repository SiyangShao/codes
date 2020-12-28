#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, x, y;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> x >> y;
		if (y % x == 0) {
			cout << x << "\n";
		} else if (x > y) {
			cout << x + y << "\n";
		} else {
			cout << (y + x * (y / x)) / 2 << "\n";
		}
	}
}