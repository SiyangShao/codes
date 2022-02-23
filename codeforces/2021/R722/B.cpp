#include <bits/stdc++.h>
#define int long long
using namespace std;
int _, n;
int a[100010], b[100010];
int sum, x, y;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	cin >> _;
	while (_--) {
		cin >> n;
		x = 0;
		y = 0;
		for (int i = 1, tmp; i <= n; i++) {
			cin >> tmp;
			if (tmp <= 0) {
				a[++x] = tmp;
			} else {
				b[++y] = tmp;
			}
		}
		sort(a+1, a + x+1);
		sort(b+1, b + y+1);
		bool flag = false;
		if (x == 0 && y != 0) {
			cout << 1 << "\n";
		} else if (x != 0 && y == 0) {
			cout << x << "\n";
		} else {
			for (int i = 2; i <= x; i++) {
				if (abs(a[i] - a[i - 1]) < b[1]) {
					flag = true;
					break;
				}
			}
			if (flag) {
				cout << x << "\n";
			} else {
				cout << x + 1 << "\n";
			}
		}
	}
}