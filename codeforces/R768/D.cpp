#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 2e5 + 7;
int cot[MAX], pre[MAX], a[MAX];
int n, k;
inline int que(int L, int R) { return pre[R] - pre[L - 1]; }
inline bool check(int x, int y) { return que(x, y) >= (n - que(x, y) + k); }
inline void fun(int x, int y) {
	int in = 0, out = 0, pre = 1, cotk = 1;
	for (int i = 1; i <= n && cotk < k; ++i) {
		if (x <= a[i] && a[i] <= y)
			in++;
		else
			out++;
		if (in > out) {
			cout << pre << " " << i << "\n";
			pre = i + 1;
			in = 0, out = 0;
			cotk++;
		}
	}
	cout << pre << " " << n << "\n";
}
void solve() {
	cin >> n >> k;
	int ansX = 0, ansY = n;
	for (int i = 1; i <= n; ++i) {
		cot[i] = pre[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cot[a[i]]++;
	}
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + cot[i];
	}
	for (int i = 1; i <= n; ++i) {
		int L = i, R = n, y = INT_MAX;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (check(i, mid)) {
				y = min(y, mid);
				R = mid - 1;
			} else
				L = mid + 1;
		}
		if ((y - i) < (ansY - ansX)) {
			ansX = i;
			ansY = y;
		}
	}
	cout << ansX << " " << ansY << "\n";
	fun(ansX, ansY);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}