#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if (![&]() {
            ll pos = 0;
            for (ll i = 0; i < m; ++i) {
                while (pos < n && t[i] != s[pos]) {
                    pos++;
                }
                if (pos == n)
                    return false;
                pos++;
            }
            return true;
        }()) {
        cout << "-1\n";
        return;
    }
    vector<ll> prefix(m + 1, n);
    prefix[0] = -1;
    for (ll i = 0; i < m; ++i) {
        ll pos = prefix[i] + 1;
        while (pos < n && t[i] != s[pos]) {
            pos++;
        }
        prefix[i + 1] = min(prefix[i + 1], pos);
    }
    vector lcs(n + 1, vector<ll>(m + 1));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            lcs[i][j] = (s[i - 1] == t[j - 1]) ? lcs[i - 1][j - 1] + 1 : 0;
        }
    }
    ll result = n;
    vector suffix(n + 1, vector<bool>(m + 1));
    suffix[n][m] = true;
    for (ll j = m; j >= 0; --j) {
        for (ll i = n; i >= 0; --i) {
            if (!suffix[i][j]) {
                if (i < n && suffix[i + 1][j])
                    suffix[i][j] = true;
                if (i < n && j < m && s[i] == t[j] && suffix[i + 1][j + 1])
                    suffix[i][j] = true;
            }
            if (suffix[i][j]) {
                auto w = lcs[i][j];
                if (prefix[j - w] + 1 > i - w)
                    continue;
                auto cost = n - i;
                if (w != j || i != j) {
                    cost += 1 + i - w + i - w - (j - w);
                }
                result = min(result, cost);
            }
        }
    }
    cout << result << "\n";
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