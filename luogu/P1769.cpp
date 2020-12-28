#include <bits/stdc++.h>
using namespace std;
double f[11][2050];
int won[2050][2050];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int m = 1 << n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++)
			cin >> won[i][j];
	}
	for (int i = 1; i <= m; i++)
		f[0][i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int pos = ceil((double)j / (1 << (i - 1)));
			int posa = ((pos & 1) == 0) ? pos - 1 : pos + 1;
			for (int k = posa * (1 << (i - 1)) - (1 << (i - 1)) + 1;
				 k <= posa * (1 << (i - 1)); k++)
				f[i][j] += f[i - 1][j] * won[j][k] / 100 * f[i - 1][k];
		}
	}
	double mx = -1;
	int ans;
	for (int i = 1; i <= m; i++) {
		if (f[n][i] > mx) {
			mx = f[n][i];
			ans = i;
		}
	}
	cout << ans << "\n";
	return 0;
}