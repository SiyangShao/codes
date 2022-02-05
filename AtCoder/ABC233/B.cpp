#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll l, r;
	string s;
	cin >> l >> r >> s;
	reverse(s.begin() + l - 1, s.begin() + r);
	cout << s << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}