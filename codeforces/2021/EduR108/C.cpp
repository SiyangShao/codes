#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
vector<int> q[maxn];
int _, n, a[maxn], maxi, b[maxn];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		cin >> n;
		maxi = 0;
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			maxi = max(maxi, a[i]);
		}
		for (int i = 1, tmp; i <= n; ++i) {
			cin >> tmp;
			q[a[i]].push_back(tmp);
		}
		for (int i = 1; i <= maxi; ++i) {
			sort(q[i].begin(), q[i].end(), greater<int>());
			for (int j = 1; j < q[i].size(); ++j) {
				q[i][j] += q[i][j - 1];
			}
			for (int j = 1; j <= q[i].size(); ++j) {
				b[j] += q[i][q[i].size() - q[i].size() % j - 1];
			}
            q[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			cout << b[i] << " ";
		}
		cout << "\n";
	}
}
// 这道题有点迷？
// 理论复杂度和我刚刚tle的做法没区别
// 但是就是过去了.....