#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll dp[300005];
char s[300005];
ll poww[300005];
vector<int> line[300005], row[300005];
int main() {
	ll ji = 1, ou = 1;
	dp[1] = 0;
	poww[0] = 1;
	poww[1] = 2;
	for (int i = 2; i <= 300000; i++)
		poww[i] = poww[i - 1] * 2 % mod;

	for (int i = 2; i <= 300000; i++) {
		ll tj = ji, to = ou;
		ou = (tj + to + tj) % mod;
		ji = to;
		dp[i] = (2 * dp[i - 1] + tj) % mod;
	}
	int n, m;
	scanf("%d%d", &n, &m);
	int cnt = 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++)
			if (s[j] == 'o')
				line[i].push_back(j), row[j].push_back(i), cnt++;
	}
	for (int i = 1; i <= n; i++) {
		int temp = 0, last = -1;
		for (auto x : line[i]) {
			if (x == last + 1)
				temp++, last = x;
			else {
				ans = (ans + poww[cnt - temp] * dp[temp]) % mod;
				temp = 1, last = x;
			}
		}
		if (temp) {
			ans = (ans + poww[cnt - temp] * dp[temp]) % mod;
		}
	}
	for (int i = 1; i <= m; i++) {
		int temp = 0, last = -1;
		for (auto x : row[i]) {
			if (x == last + 1)
				temp++, last = x;
			else {
				ans = (ans + poww[cnt - temp] * dp[temp]) % mod;
				temp = 1, last = x;
			}
		}
		if (temp) {
			ans = (ans + poww[cnt - temp] * dp[temp]) % mod;
		}
	}
	printf("%lld", ans);
	return 0;
}