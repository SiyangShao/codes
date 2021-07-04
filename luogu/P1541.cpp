#include <bits/stdc++.h>
using namespace std;
int n, m, x[41][41][41][41], y[5], z[360], tmp;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> z[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		y[tmp]++;
	}
	x[0][0][0][0] = z[1];
	for (int a = 0; a <= y[1]; a++) {
		for (int b = 0; b <= y[2]; b++) {
			for (int c = 0; c <= y[3]; c++) {
				for (int d = 0; d <= y[4]; d++) {
					int num = 1 + a + 2 * b + 3 * c + 4 * d;
					if (a != 0) {
						x[a][b][c][d] =
							max(x[a - 1][b][c][d] + z[num], x[a][b][c][d]);
					}
					if (b != 0) {
						x[a][b][c][d] =
							max(x[a][b - 1][c][d] + z[num], x[a][b][c][d]);
					}
					if (c != 0) {
						x[a][b][c][d] =
							max(x[a][b][c - 1][d] + z[num], x[a][b][c][d]);
					}
					if (d != 0) {
						x[a][b][c][d] =
							max(x[a][b][c][d - 1] + z[num], x[a][b][c][d]);
					}
				}
			}
		}
	}
	cout << x[y[1]][y[2]][y[3]][y[4]] << endl;
}