#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void solve() {
	string s, t;
	while (cin >> s >> t) {
		int N = s.length();
		int differ;
		if (t[0] <= s[0]) {
			differ = t[0] + 26 - s[0];
		} else {
			differ = t[0] - s[0];
		}
		for (int i = 0; i < N; ++i) {
			int dif;
			if (t[i] <= s[i]) {
				dif = t[i] + 26 - s[i];
			} else {
				dif = t[i] - s[i];
			}
			if (dif != differ) {
				cout << "No";
				return;
			}
		}
		cout << "Yes";
		return;
	}
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}