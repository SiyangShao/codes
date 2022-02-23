#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
int a[maxn], b[maxn], dp[maxn];
int n, num;
int pre[maxn];
int main() {
	memset(dp, 0x3f, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	num = n - 1;
	dp[n] = 0;
	for (int i = n; i > 0; --i) {
		int j = i + b[i];
		while (j - a[j] <= num) {
			dp[num] = dp[i] + 1;
			pre[num] = i;
			num--;
		}
	}
	if (dp[0] >= 0x3f3f3f3f) {
		puts("-1");
	} else {
		printf("%d\n", dp[0]);
		int begin = 0;
		vector<int> ans;
		while (begin != n) {
			ans.push_back(begin);
			begin = pre[begin];
		}
		reverse(ans.begin(), ans.end());
		for (auto i : ans) {
			printf("%d ", i);
		}
	}
}