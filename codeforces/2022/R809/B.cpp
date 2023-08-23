#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
        i--;
    }
    vector<vector<ll>> E(n, vector<ll>());
    for (ll i = 0; i < n; ++i) {
        E[i].clear();
    }
    for (ll i = 0; i < n; ++i) {
        E[a[i]].emplace_back(i);
    }
    for (ll i = 0; i < n; ++i) {
        if (E[i].empty()) {
            cout << "0 ";
            continue;
        }
        ll ans = 1, m = E[i].size();
        vector<ll> dp(m);
        for (ll j = 0; j < m; ++j) {
            dp[j] = 1;
        }
        ll odd = 0, even = 0;
        ll cur = 0;
        for (ll j = 1; j < m; ++j) {
            if (E[i][j] - E[i][j - 1] == 1) {
                dp[j] = max(dp[j], dp[j - 1] + 1);
            }
            while (E[i][j] - E[i][cur] > 2) {
                if (E[i][cur] % 2 == 0) {
                    even = max(even, dp[cur]);
                } else {
                    odd = max(odd, dp[cur]);
                }
                cur++;
            }
            if (E[i][j] % 2 == 1) {
                dp[j] = max(dp[j], even + 1);
            } else {
                dp[j] = max(dp[j], odd + 1);
            }
            ans = max(ans, dp[j]);
            // cout<<dp[j]<<" ";
        }
        cout << ans << " ";
    }
    cout << "\n";
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