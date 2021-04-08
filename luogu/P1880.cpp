#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
int n, min1 = 0x3f3f3f3f, max1, f1[maxn][maxn], f2[maxn][maxn], num[maxn],
	   s[maxn];
inline int d(int i, int j) { return s[j] - s[i - 1]; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		num[i + n] = num[i];
	}
	for (int i = 1; i <= n + n; i++) {
		s[i] = s[i - 1] + num[i];
	}
	for (int p = 1; p < n; p++) {
		for (int i = 1, j = i + p; j < n + n && i < n + n; i++, j = i + p) {
			f2[i][j] = 0x3f3f3f3f;
			for (int k = i; k < j; k++) {
				f1[i][j] = max(f1[i][j], f1[i][k] + f1[k + 1][j] + d(i, j));
				f2[i][j] = min(f2[i][j], f2[i][k] + f2[k + 1][j] + d(i, j));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		max1 = max(max1, f1[i][i + n - 1]);
		min1 = min(min1, f2[i][i + n - 1]);
	}
	cout << min1 << "\n" << max1 << "\n";
}