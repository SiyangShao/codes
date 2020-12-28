#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    map<ll, ll> mp;
    for (auto &i : a) {
        for (auto &j : i) {
            cin >> j;
        }
        partial_sum(i.begin(), i.end(), i.begin());
        partial_sum(i.begin(), i.end(), i.begin());
        mp[i.back()]++;
    }
    for (int i = 0; i < n; ++i) {
        if (mp[a[i][m - 1]] == 1) {
            cout << i + 1 << " ";
            cout << -a[i][m - 1] + a[(i + 1) % n][m - 1] << "\n";
            break;
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