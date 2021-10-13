#include <bits/stdc++.h>

using namespace std;
int t = 1, n;
int a[1000010], b[1000010], c[1000010];
int C;
int l, r, mid;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		/***
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		 ***/
		cin >> n;
		C = 1;
		b[0] = 0, b[1] = 0, b[2] = 0;
		c[0] = 0, c[1] = 0, c[2] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] < b[C]) {
				C++;
				b[C] = a[i];
				c[i] = C;
			} else {
				l = 1, r = C;
				while (l + 1 <= r) {
					mid = (l + r) / 2;
					if (b[mid] > a[i]) {
						l = mid + 1;
					} else {
						r = mid;
					}
				}
				b[r] = a[i];
				c[i] = r;
			}
		}
		cout << C << "\n";
		for (int i = 1; i <= n; i++) {
			cout << c[i] << " ";
		}
		cout << "\n";
	}
}