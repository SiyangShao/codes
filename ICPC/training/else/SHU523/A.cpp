#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, t, k;
	scanf("%d%d%d", &n, &t, &k);
	int l = 0, r = n + 1;
	int mid, tmp;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		printf("? 1 %d\n", mid);
		fflush(stdout);
		scanf("%d", &tmp);
		if (mid - tmp < k) {
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("! %d\n", l + 1);
	fflush(stdout);
}