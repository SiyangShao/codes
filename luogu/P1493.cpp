#include <cstdio>
#include <cstdlib>

int n;
long long a, b, c;
long long m1, m2;
int dp[2123][2123];
int ans(0);
int main() {
	scanf("%d%lld%d%lld", &n, &a, &b, &c);
	for (int i(0); i != n; ++i) {
		long long v1, v2;
		scanf("%lld%lld", &v1, &v2);
		if (v1 > m1)
			m1 = v1;
		if (v2 > m2)
			m2 = v2;
		int x(v1), y(v2);

		while (x != 0) {
			int l((a * (v1 - x) + b * v2 - c) / b), r(v2 + 1);
			if (l < 0)
				l = 0;
			while (r > l) {
				int mid((l + r) / 2);
				if (a * (v1 - x) + b * (v2 - mid) <= c) {
					y = mid;
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			if (y <= v2 + 1) //判断范围……不判断可能会出事情
			{
				++dp[x][y]; //差分
				--dp[x][v2 + 1];
			}
			y = v2 +
				1; //这一步必不可少！！
				   //如果你不更新y为一个无效值（越大越好，至少大于v2），那么如果下次二分找不出有效的y值，就会使用上次的y值！而上次的y值对于现在的x已经没有意义了……
				   //当然……如果你的y定义在这个循环内并且初始化为一个无效值……那么就当没看见我这三行注释……
			--x;
		}
	}
	for (int i(0); i <= m1; ++i) {
		int sum(0);
		for (int j(0); j <= m2; ++j) {
			sum += dp[i][j]; //前缀和获得原dp数组
			if (sum > ans)
				ans = sum;
		}
	}
	printf("%d\n", ans);
	return 0;
}