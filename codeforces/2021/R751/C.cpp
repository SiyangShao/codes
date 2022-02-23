#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[200010], _;
int bits[30];
bool flag;
inline void judge(int x) {
	int i = 0;
	while (x) {
		if (x & 1) {
			bits[i]++;
		}
		x >>= 1;
		i++;
	}
}
signed main() {
	scanf("%d", &_);
	while (_--) {
		memset(bits, 0, sizeof(bits));
		scanf("%lld", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			judge(a[i]);
		}
		printf("1");
		for (int i = 2; i <= n; ++i) {
			flag = true;
			for (int j = 0; j < 30; ++j) {
				if (bits[j] % i != 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				printf(" %d", i);
			}
		}
		puts("");
	}
}