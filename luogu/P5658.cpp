#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 7;
ll n, h[N], w[N], fa[N], ans;
ll cn, hd[N], to[N], nt[N];
vector<ll> E[N];
char s[N];
void dfs(ll x) {
	w[x] = w[fa[x]];
	if (s[x] == '(')
		w[x] = x;
	else if (w[x])
		h[x] = 1 + h[fa[w[x]]], w[x] = w[fa[w[x]]];
	for (auto i : E[x]) {
		dfs(i);
	}
}
int main() {
	scanf("%lld%s", &n, s + 1);
	for (ll i = 2, x; i <= n; i++) {
		scanf("%lld", &x);
		fa[i] = x;
		E[x].push_back(i);
	}
	dfs(1), ans = h[1];
	for (ll i = 2; i <= n; i++)
		h[i] += h[fa[i]], ans ^= (i * h[i]);
	printf("%lld\n", ans);
	return 0;
}