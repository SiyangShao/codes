#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 200010, MOD = 998244353;
ll t, n, sum = 0, pre[N], cnt[N], ans[N];
vector<ll> fac[N];
vector<array<ll, 3>> e[N];
ll qpow(ll x, ll y) {
    return y ? qpow(x * x % MOD, y >> 1) * (y & 1 ? x : 1) % MOD : 1;
}
void dfs(ll x, ll fa) {
    for (auto i : e[x]) {
        ll y = i[0], a = i[1], b = i[2];
        if (y == fa)
            continue;
        for (auto k : fac[b])
            cnt[k]++;
        for (auto k : fac[a])
            ans[k] = max(ans[k], -(--cnt[k]));
        dfs(y, x);
        for (auto k : fac[a])
            cnt[k]++;
        for (auto k : fac[b])
            cnt[k]--;
    }
}
void solve(ll x, ll fa, ll val) {
    sum = (sum + val) % MOD;
    for (auto i : e[x]) {
        ll y = i[0], a = i[1], b = i[2];
        if (y == fa)
            continue;
        solve(y, x, val * qpow(a, MOD - 2) % MOD * b % MOD);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 2; i < N; i++)
        if (!pre[i])
            for (int j = i; j < N; j += i)
                pre[j] = i;
    for (int i = 1; i < N; i++) {
        int t = i;
        while (t > 1)
            fac[i].push_back(pre[t]), t /= pre[t];
    }
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cnt[i] = ans[i] = 0;
            e[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int x, y, a, b;
            cin >> x >> y >> a >> b;
            e[x].push_back({y, a, b});
            e[y].push_back({x, b, a});
        }
        dfs(1, 0);
        auto res = 1ll;
        for (int i = 1; i <= n; i++)
            res = res * qpow(i, ans[i]) % MOD;
        sum = 0;
        solve(1, 0, res);
        cout << sum << '\n';
    }
    return 0;
}