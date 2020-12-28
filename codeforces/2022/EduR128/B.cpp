#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> lst(n);
    for (auto &i : lst) {
        cin >> i;
    }
    vector<vector<ll>> mp(n, vector<ll>(m));
    ll cnt = 0;
    ll left = m, up = n;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (lst[i][j] == 'R') {
                left = min(left, j - 0);
                up = min(up, i - 0);
                mp[i][j] = 1;
                cnt = 1;
            } else {
                mp[i][j] = 0;
            }
        }
    }
    if (cnt == 0) {
        cout << "NO\n";
        return;
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (mp[i][j] == 1) {
                if (i - up <= 0 && j - left <= 0) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
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