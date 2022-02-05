#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[1000010];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int, int>> a(n);
		for (int i = 1, tmp; i <= n; ++i) {
			cin >> tmp;
			a[i - 1] = {tmp, i};
		}
		sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
			return x.first > y.first;
		});
		int r = 2;
		int L = 0;
		for (auto i : a) {
			if (r % 2LL == 0) {
				ans[i.second] = r / 2;
				L += 2LL * ans[i.second] * i.first;
			} else {
				ans[i.second] = -r / 2;
				L += -2LL * ans[i.second] * i.first;
			}
			r++;
		}
		cout << L << "\n";
		for (int i = 0; i <= n; ++i) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}