#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 2e5 + 7;
constexpr int logn = 21;
int f[maxn][logn + 1], Logn[maxn + 1];

inline int read() { //快读
	int c = getchar();
	int x = 0, tmp = 1;
	while (c < '0' || c > '9') {
		if (c == '-')
			tmp = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * tmp;
}

void pre() { //准备工作，初始化
	Logn[1] = 0;
	Logn[2] = 1;
	for (int i = 3; i < maxn; i++) {
		Logn[i] = Logn[i / 2] + 1;
	}
}

int main() {
	int n = read();
	for (int i = 1; i <= n; i++)
		f[i][0] = read();
	pre();
	for (int j = 1; j <= logn; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
	int change = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		// int x = read(), y = read();
		// int s = Logn[y - x + 1];
		// printf("%d\n", gcd(f[x][s], f[y - (1 << s) + 1][s]));
		if (f[i][0] == 1) {
			change = i;
			ans++;
		} else {
			int x = change + 1, y = i;
			bool flag = false;
			while (x <= y) {
				int mid = (x + y) / 2;
				int s = Logn[i - mid + 1];
				int tmp = gcd(f[mid][s], f[i - (1 << s) + 1][s]);
				if (tmp > i - mid + 1) {
					y = mid - 1;
				} else if (tmp < i - mid + 1) {
					x = mid + 1;
				} else {
					flag = true;
					break;
				}
			}
			if (flag) {
				ans++;
				change = i;
			}
		}
		printf("%d ", ans);
	}
	return 0;
}
