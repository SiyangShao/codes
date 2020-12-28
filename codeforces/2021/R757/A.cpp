#include <bits/stdc++.h>
using namespace std;
int t, n, l, r, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> l >> r >> k;
		vector<int> ans;
		for (int i = 1, tmp; i <= n; ++i) {
			cin >> tmp;
			if (tmp >= l && tmp <= r) {
				ans.push_back(tmp);
			}
		}
		sort(ans.begin(), ans.end());
		int num = 0;
		for (auto i : ans) {
			if (k >= i) {
				k -= i;
				num++;
			} else {
				break;
			}
		}
		cout << num << "\n";
	}
}