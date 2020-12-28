#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 我走在每天必须面对的分岔路
// 我怀念过去单纯美好的小幸福
auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end(), greater<>());
    vector<ll> cost;
    cost.assign(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cost[i] = a[i - 1] + cost[i - 1];
    }
    while (q--) {
        ll k;
        cin >> k;
        auto pos = lower_bound(cost.begin(), cost.end(), k);
        if (pos == cost.end()) {
            cout << "-1\n";
        } else {
            cout << pos - cost.begin() << "\n";
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