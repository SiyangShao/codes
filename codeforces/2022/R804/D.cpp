#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), dp(n);
    for (auto &i : a) {
        cin >> i;
        i--;
    }
    vector can(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; ++i) {
        vector<ll> num(n, 0);
        num.assign(n, 0);
        ll tp = 0;
        ll len = 0;
        for (ll j = i; j < n; ++j) {
            num[a[j]]++;
            len++;
            tp = max(tp, num[a[j]]);
            if (tp > len / 2) {
                can[i][j] = 0;
            } else {
                can[i][j] = 1;
            }
        }
    }
    auto judge = [&](ll l, ll r) {
        if (l > r) {
            return true;
        }
        if ((r - l) % 2 == 0) {
            return false;
        }
        return can[l][r] == 1;
    };

    for (ll i = 0; i < n; ++i) {
        if (judge(0, i - 1)) {
            dp[i] = 1;
        }
        for (ll j = 0; j < i; ++j) {
            if (a[i] == a[j] && dp[j] != 0 && judge(j + 1, i - 1)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (judge(i + 1, n - 1)) {
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}