#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> mp[26];
void solve() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		mp[s[i] - 'a'].emplace_back(i + 1);
	}
	int q;
	string t;
	cin >> q;
	while (q--) {
		cin >> t;
		vector<int> num(26);
		for (auto i : t) {
			num[i - 'a']++;
		}
		int ans = 0;
		for (int i = 0; i < 26; ++i) {
			if (num[i])
				ans = max(ans, mp[i][num[i] - 1]);
		}
		cout << ans << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}