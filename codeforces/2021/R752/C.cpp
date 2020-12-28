#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, a[100010], b[100010], maxn;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	maxn = 1;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		bool flag = false;
		for (int i = 1; i <= n; ++i) {
			flag = false;
			for (int j = 1; j <= min(i + 1,23); ++j) {
				if (a[i] % j != 0) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}
		if (!flag) {
			puts("NO");
		} else {
			puts("YES");
		}
	}
}