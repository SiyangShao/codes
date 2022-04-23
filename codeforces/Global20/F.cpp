#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> pos(n);
    pos.assign(n, vector<ll>());
    for (auto &i : a) {
        cin >> i;
        i--;
    }
    for (int i = 0; i < n; ++i) {
        pos[a[i]].emplace_back(i);
    }
    size_t maxi = 0;
    vector<ll> p, inv(n);
    for (auto &v : pos) {
        maxi = max(maxi, v.size());
        for (auto x : v) {
            p.emplace_back(x);
        }
    }
    for (int i = 0; i < n; ++i) {
        inv[p[i]] = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        cout << a[(inv[i] + maxi) % n] + 1 << " \n"[i == n - 1];
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