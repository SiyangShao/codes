#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		bool flag = false;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		if (n % 2 == 0) {
			puts("YES");
		} else {
			for (int i = 2; i <= n; ++i) {
				if (a[i] <= a[i - 1]) {
					flag = true;
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
}