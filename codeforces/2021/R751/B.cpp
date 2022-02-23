#include <bits/stdc++.h>
using namespace std;
int a[2010][2010];
int n, q, x, k, t, _;
map<int, int> mp;
bool flag;
int main() {
	scanf("%d", &_);
	while (_--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i][0]);
		}
		t = n;
		for (int i = 1; i <= n; ++i) {
			mp.clear();
			for (int j = 1; j <= n; ++j) {
				mp[a[j][i - 1]]++;
			}
			for (int j = 1; j <= n; ++j) {
				a[j][i] = mp[a[j][i - 1]];
			}
			flag = true;
			for (int j = 1; j <= n; ++j) {
				if (a[j][i - 1] != a[j][i]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				t = i;
				break;
			}
		}
		scanf("%d", &q);
		while (q--) {
			scanf("%d%d", &x, &k);
			if (k >= t) {
				k = t;
			}
			printf("%d\n", a[x][k]);
		}
	}
}