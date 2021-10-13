#include <bits/stdc++.h>
using namespace std;
int _, n;

int main() {
	scanf("%d", &_);
	while (_--) {
		scanf("%d", &n);
		vector<double> x;
		vector<double> y;
		double a, b;
		for (int i = 1; i <= 2 * n; i++) {
			scanf("%lf%lf", &a, &b);
			if (a == 0) {
				y.push_back(abs(b));
			} else {
				x.push_back(abs(a));
			}
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		double ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += sqrt(x[i] * x[i] + y[i] * y[i]);
		}
		printf("%.9lf\n", ans);
	}
}