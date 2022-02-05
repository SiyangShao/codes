#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdio.h>

int main() {
	// clock_t start,end;
	double n, m, k;
	double ans = 0;
	// std::cin >> n >> m >> k;
	scanf("%lf%lf%lf", &n, &m, &k);
	// start=clock();
	// int q = log10(m);
	if (n - k < 1e5)
		for (double i = k; i <= n; i++) {
			if (i <= m)
				ans++;
			else {
				ans += m / i;
			}
		}
	else {
		if (m >= k) {
			ans = m - k + 1;
			ans += m * (log(n) - log(m));
		} else {
			ans += m * (log(n) - log(k - 1));
		}
	}
	printf("%.10lf\n", ans);
	// end=clock();
	// printf("%d\n",end-start);
	return 0;
}