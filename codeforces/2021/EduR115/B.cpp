#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[1010][10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 5; ++j) {
				cin >> a[i][j];
			}
		}
		int flag = false;
		for (int i = 1; i <= 5; ++i) {
			for (int j = i + 1; j <= 5; ++j) {
				int ok = 1, c1 = 0, c2 = 0, c3 = 0;
				for (int k = 1; k <= n; ++k) {
					if ((a[k][i]) && (a[k][j])) {
						c1++;
					} else if (!a[k][i] && a[k][j]) {
						c2++;
					} else if ((a[k][i]) && !a[k][j]) {
						c3++;
					} else {
						ok = 0;
						break;
					}
				}
				if (ok && c2 <= n / 2 && c3 <= n / 2) {
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
}