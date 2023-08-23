#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mpa[10][10], mpb[10][10];
inline void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		u--, v--;
		mpa[u][v] = mpa[v][u] = 1;
	}
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		u--, v--;
		mpb[u][v] = mpb[v][u] = 1;
	}
	vector<int> mp(n);
	iota(mp.begin(), mp.end(), 0);
	do {
		bool flag = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (mpa[i][j] != mpb[mp[i]][mp[j]]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			cout << "Yes\n";
			return;
		}
	} while (next_permutation(mp.begin(), mp.end()));
	cout << "No\n";
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