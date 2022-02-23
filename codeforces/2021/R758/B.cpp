#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int ans[100010];
void solve() {
	cin >> n >> a >> b;
	if (abs(a - b) > 1 || a + b > n - 2) {
		cout << "-1\n";
	} else {
		if (a - b == 1) {
			int top = n, l = 1;
			for (int i = 2; i <= 2 * a; i += 2) {
				ans[i] = top;
				top--;
				ans[i - 1] = l;
				l++;
			}
			for (int i = 2 * a + 1; i <= n; ++i) {
				ans[i] = top;
				top--;
			}
		} else if (a == b) {
			int top = n, l = 1;
			for (int i = 2; i <= 2 * a; i += 2) {
				ans[i] = top;
				top--;
				ans[i - 1] = l;
				l++;
			}
			for (int i = 2 * a + 1; i <= n; ++i) {
				ans[i] = l;
				l++;
			}
		} else {
			int top = n, l = 1;
			for (int i = 2; i <= 2 * b; i += 2) {
				ans[i] = l;
				l++;
				ans[i - 1] = top;
				top--;
			}
			for (int i = 2 * b + 1; i <= n; ++i) {
				ans[i] = l;
				l++;
			}
		}
		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}