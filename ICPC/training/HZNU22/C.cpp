#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18 + 7;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> len;
    len.clear();
    for (auto &i : a) {
        cin >> i;
    }
    len.emplace_back(INF);
    vector<ll> pre(n);
    pre.assign(n, 0);
    for (ll i = 0; i + 1 < n; ++i) {
        len.emplace_back(a[i + 1] - a[i]);
    }
    sort(len.begin(), len.end());
    pre[0] = len[0];
    for (ll i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + len[i];
    }
    ll q;
    cin >> q;
    while (q--) {
        ll t;
        cin >> t;
        auto pos = lower_bound(len.begin(), len.end(), t) - len.begin();
        if (pos == 0) {
            cout << t * n << "\n";
        } else {
            cout << pre[pos - 1] + (n - pos) * t << "\n";
        }
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}