#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve() {
	ll n;
	cin >> n;
	ll sum = 0;
	vector<ll> a(n);
	for (auto &i : a) {
		cin >> i;
		sum += i;
	}
	if (sum % n) {
		cout << 1 << "\n";
	} else {
		cout << 0 << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
}