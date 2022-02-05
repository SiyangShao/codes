#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
void solve() {
	unordered_map<int, int> mp;
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
		mp[abs(i)]++;
	}
	int cnt = 0;
	for (auto i : mp) {
		if (i.first == 0) {
			cnt++;
		} else {
			if (i.second >= 2) {
				cnt += 2;
			} else {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}