#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, x, n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> x >> n;
		if (x & 1 == 1) {
			if (n % 4 == 1) {
				cout << x + n << "\n";
			} else if (n % 4 == 2) {
				cout << x - 1 << "\n";
			} else if (n % 4 == 3) {
				cout << x - 1 - n << "\n";
			} else {
				cout << x << "\n";
			}
		} else {
			if (n % 4 == 1) {
				cout << x - n << "\n";
			} else if (n % 4 == 2) {
				cout << x + 1 << "\n";
			} else if (n % 4 == 3) {
				cout << x + 1 + n << "\n";
			} else {
				cout << x << "\n";
			}
		}
	}
}