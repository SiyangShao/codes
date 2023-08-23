#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		if (n % 2 == 0)
			for (auto i = a.begin(); i < a.end(); i += 2) {
				cout << -*(i + 1) << " " << *i << " ";
			}
		else {
			for (auto i = a.begin(); i < a.end() - 3; i += 2) {
				cout << -*(i + 1) << " " << *i << " ";
			}
			auto x = *(a.end() - 3), y = *(a.end() - 2), z = *(a.end() - 1);
			if (x + y != 0) {
				cout << -z << " " << -z << " " << x + y;
			} else if (x + z != 0) {
				cout << -y << " " << x + z << " " << -y;
			} else {
				cout << y + z << " " << -x << " " << -x;
			}
		}
		cout << "\n";
	}
}