#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, t, ans;
vector<int> lef;
vector<int> rig;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> t;
	for (int i = 1, tmp; i <= n; i++) {
		cin >> tmp;
		if (tmp < 0) {
			lef.push_back(-tmp);
		} else {
			rig.push_back(tmp);
		}
	}
	sort(lef.begin(), lef.end());
	sort(rig.begin(), rig.end());
	ans = max(upper_bound(rig.begin(), rig.end(), t) - rig.begin(),
			  upper_bound(lef.begin(), lef.end(), t) - lef.begin());
	for (int i = 0; i < lef.size(); i++) {
		if (lef[i] > t) {
			break;
		}
		int tmp = t - 2 * lef[i];
		int res = 0;
		if (tmp > 0) {
			res = upper_bound(rig.begin(), rig.end(), tmp) - rig.begin();
		}
		ans = max(ans, res + i + 1);
	}
	for (int i = 0; i < rig.size(); i++) {
		if (rig[i] > t) {
			break;
		}
		int tmp = t - 2 * rig[i];
		int res = 0;
		if (tmp > 0) {
			res = upper_bound(lef.begin(), lef.end(), tmp) - lef.begin();
		}
		ans = max(ans, res + i + 1);
	}
	cout << ans << "\n";
}