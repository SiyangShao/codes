#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
    }
    ll cnt = 0;
    for (auto &[u, v] : mp) {
        cnt = max(cnt, v);
    }
    auto tmp = cnt;
    ll t = 0;
    while (tmp < n) {
        tmp *= 2;
        t++;
    }
    cout << t + n - cnt << "\n";
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