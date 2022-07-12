#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * @brief
 * X11X
 * 1001
 * 1001
 * 1001
 * X11X
 * @return auto
 */
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (auto &i : mp) {
        cin >> i;
    }
    vector M(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            M[i][j] = mp[i - 1][j - 1] - '0';
            M[i][j] += M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1];
        }
    }
    auto get = [&](auto x1, auto y1, auto x2, auto y2) {
        return M[y2][x2] + M[y1 - 1][x1 - 1] - M[y1 - 1][x2] - M[y2][x1 - 1];
    };
    auto getsum = [&](auto x1, auto y1, auto x2, auto y2) {
        ll res = get(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
        res += x2 - x1 - 1 - get(x1 + 1, y1, x2 - 1, y1);
        res += x2 - x1 - 1 - get(x1 + 1, y2, x2 - 1, y2);
        res += y2 - y1 - 1 - get(x1, y1 + 1, x1, y2 - 1);
        res += y2 - y1 - 1 - get(x2, y1 + 1, x2, y2 - 1);
        return res;
    };

    ll ans = 16;
    for (ll L = 1; L <= n; ++L) {
        for (ll R = L + 4; R <= n; ++R) {
            ll i = 1;
            for (ll j = 4; j <= m; ++j) {
                ans = min(ans, getsum(i, L, j, R));
                if ([&]() {
                        ll x1 = i, x2 = j - 2;
                        ll y1 = L, y2 = R;
                        ll res1 = y2 - y1 - 1 - get(x1, y1 + 1, x1, y2 - 1) +
                                  x2 - x1 - get(x1 + 1, y1, x2, y1) + x2 - x1 -
                                  get(x1 + 1, y2, x2, y2) +
                                  get(x1 + 1, y1 + 1, x2, y2 - 1);
                        ll res2 = y2 - y1 - 1 - get(x2, y1 + 1, x2, y2 - 1);
                        return res2 < res1;
                    }()) {
                    i = j - 2;
                }
            }
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