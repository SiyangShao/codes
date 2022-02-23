#include <bits/stdc++.h>
using namespace std;
int _, n;
int a[200010], b[200010];
bool judge(int length) {
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (b[i] >= sum && a[i] >= length - 1 - sum) {
			sum++;
		}
	}
	if (sum < length) {
		return false;
	} else {
		return true;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> _;
	while (_--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i];
		}
		int l = 1, r = n;
		int mid = 1, ans = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (judge(mid)) {
				l = mid + 1;
				ans = ans < mid ? mid : ans;
			} else {
				r = mid - 1;
			}
		}
		cout << ans << "\n";
	}
}