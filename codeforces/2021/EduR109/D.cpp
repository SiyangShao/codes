#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int t, n;
int one[N], a[N], zero[N], f[N][N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int k = 0, z = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == 1)
			one[++k] = i;
		else {
			zero[++z] = i;
		}

	memset(f, 0x3f, sizeof f);

	for (int i = 0; i <= N; i++)
		f[i][0] = 0;

	for (int i = 1; i <= z; i++) {
		for (int j = 1; j <= k; j++) {
			f[zero[i]][j] = min(f[zero[i - 1]][j],
								f[zero[i - 1]][j - 1] + abs(zero[i] - one[j]));
		}
	}
	cout << f[zero[z]][k] << endl;
	return 0;
}