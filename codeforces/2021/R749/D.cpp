#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, d;
int ans[N], a[N];
signed main() {

	cin >> n;
	ans[n] = 1;
	for (int i = 2; i <= n; ++i) {
		printf("? ");
		for (int j = 1; j < n; j++)
			printf("%d ", i);
		printf("1\n");
		int k;
		cin >> k;
		if (k)
			ans[n]++;
		else
			break;
	}
	for (int i = 1; i <= n; ++i) {
		if (i == ans[n])
			continue;
		printf("? ");
		for (int j = 1; j < n; j++)
			printf("%d ", n - i + 1);
		printf("%d\n", n + 1 - ans[n]);
		int x;
		cin >> x;
		ans[x] = i;
	}
	printf("! ");
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);

	return 0;
}
