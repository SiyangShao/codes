//TLE做法 正解不会
#include <bits/stdc++.h>
using namespace std;
int n, q, l, r;
int a[300010];
int vis[300010];
bool check(int x) {
	memset(vis, 0, sizeof(vis));
	int tmp = l;
	int sum = 1;
	for (int i = l; i <= r; i++) {
		vis[a[i]]++;
		if (vis[a[i]] > ceil(double(i - tmp + 1) / 2)) {
			tmp = i;
			vis[a[i]] = 1;
			sum++;
		}
	}
	if (sum > x) {
		return false;
	} else {
		return true;
	}
}
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (q--) {
		cin >> l >> r;
		int lef = 1, rig = r - l + 1;
		int mid = (lef + rig) / 2;
		while (lef <= rig) {
			mid = (lef + rig) / 2;
			if (check(mid)) {
				rig = mid - 1;
				// cout << lef<<" "<<rig << "\n";
			} else {
				lef = mid + 1;
			}
		}
		cout << lef << "\n";
	}
}