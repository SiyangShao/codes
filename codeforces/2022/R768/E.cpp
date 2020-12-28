#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int cnt = 0;
	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]].emplace_back(i);
	}
	int l = 0, r = n - 1;
	for (int i = 0; i < n; ++i) {
		if (mp[a[i]].size() > 1) {
			r = mp[a[i]][mp[a[i]].size() - 1];
			l = max(l, i + 1);
			int now = r;
			int nbegin = now;
			mp[a[i]].clear();
			for (int j = l; j < r; ++j) {
				if (mp[a[j]].size() > 1 &&
					mp[a[j]][mp[a[j]].size() - 1] > now) {
					now = mp[a[j]][mp[a[j]].size() - 1];
					nbegin = mp[a[j]][0];
				}
				cnt++;
			}
			if (now == r) {
				i = now;
			} else {
				i = nbegin - 1;
				l = r;
				cnt--;
			}
		}
	}
	cout << cnt << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	while (_--) {
		solve();
	}
}