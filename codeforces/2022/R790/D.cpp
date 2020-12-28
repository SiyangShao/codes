#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 我走在每天必须面对的分岔路
// 我怀念过去单纯美好的小幸福
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mp(n, vector<ll>(m));
    for (auto &i : mp) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    vector<ll> l, r;
    l.assign(n + m + 10, 0), r.assign(n + m + 10, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            l[i - j + m] += mp[i][j];
            r[j + i] += mp[i][j];
        }
    }
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cnt = max(cnt, l[i - j + m] + r[i + j] - mp[i][j]);
        }
    }
    cout << cnt << "\n";
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