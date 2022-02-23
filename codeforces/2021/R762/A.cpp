#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void solve() {
	string s;
	cin >> s;
	int N = s.length();
	if (N % 2 == 1) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < N / 2; ++i) {
		if (s[i] != s[i + N / 2]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}