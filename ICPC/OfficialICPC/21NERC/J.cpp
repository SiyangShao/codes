#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<vector<ll>> mp, dp, fro;
vector<int> fa;
auto subtree(int l, int r) {
    if (l > r)
        return 0LL;
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    ll cnt = LONG_LONG_MAX;
    for (ll k = l; k <= r; ++k) {
        auto tmp = subtree(l, k - 1) + subtree(k + 1, r);
        if (tmp < cnt) {
            cnt = tmp;
            fro[l][r] = k;
        }
    }
    for (ll i = l; i <= r; ++i) {
        cnt += mp[i][n] - (mp[i][r] - mp[i][l - 1]);
    }
    return dp[l][r] = cnt;
}
auto build(int l, int r, int up) {
    if (l > r)
        return;
    if (l == r) {
        fa[l] = up;
        return;
    }
    auto k = fro[l][r];
    // cout << l << " " << r << " " << k << endl;
    fa[k] = up;
    build(l, k - 1, k);
    build(k + 1, r, k);
}
auto solve() {
    cin >> n;
    fa.assign(n + 1, 0);
    mp.assign(n + 1, vector<ll>(n + 1, 0));
    dp.assign(n + 1, vector<ll>(n + 1, -1));
    fro.assign(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            mp[i][j] += mp[i][j - 1];
        }
    }
    subtree(1, n);
    // cout << fro[1][n] << " ";
    build(1, n, 0);
    for (int i = 1; i <= n; ++i) {
        cout << fa[i] << " ";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}