#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> c(n, vector<ll>(m, 0));
    vector<ll> dif(n, 0);
    map<ll, ll> mp;
    for (auto &i : c) {
        for (auto &j : i) {
            cin >> j;
        }
        partial_sum(i.begin(), i.end(), i.begin());
        partial_sum(i.begin(), i.end(), i.begin());
        mp[i[m - 1]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (mp[c[i][m - 1]] == 1) {
            cout << i + 1 << " " << -c[i][m - 1] + c[(i + 1) % n][m - 1]
                 << "\n";
            return;
        }
    }
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