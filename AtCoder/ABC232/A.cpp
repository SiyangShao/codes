#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void solve() {
	string s;
	cin >> s;
	cout << (s[0] - '0') * (s[2] - '0');
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