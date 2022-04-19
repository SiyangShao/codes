#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct SegmentTree {
    using ll = long long;
    vector<ll> d, a, b;
    auto init(ll n) {
        a.assign(n + 1, 0);
        d.assign(4 * (n + 1), 0);
        b.assign(4 * (n + 1), 0);
    }
    auto build(ll s, ll t, ll p) {
        if (s == t) {
            d[p] = a[s];
            return;
        }
        auto m = s + ((t - s) >> 1);
        build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] + d[p * 2 + 1];
    }
    auto get_sum(ll l, ll r, ll s, ll t, ll p) {
        if (l <= s && r >= t) {
            return d[p];
        }
        auto m = s + ((t - s) >> 1);
        auto sum = 0LL;
        if (b[p]) {
            d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
            b[p * 2] += b[p], b[p * 2 + 1] += b[p];
            b[p] = 0;
        }
        if (l <= m) {
            sum += get_sum(l, r, s, m, p * 2);
        }
        if (r > m) {
            sum += get_sum(l, r, m + 1, t, p * 2 + 1);
        }
        return sum;
    }
    auto update(ll l, ll r, ll c, ll s, ll t, ll p) {
        if (l <= s && t <= r) {
            d[p] += (t - s + 1) * c, b[p] += c;
            return;
        }
        int m = s + ((t - s) >> 1);
        if (b[p] && s != t) {
            d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
            b[p * 2] += b[p], b[p * 2 + 1] += b[p];
            b[p] = 0;
        }
        if (l <= m)
            update(l, r, c, s, m, p * 2);
        if (r > m)
            update(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] + d[p * 2 + 1];
    }
};
auto solve() {
    ll n, m;
    cin >> n >> m;
    SegmentTree st;
    st.init(n);
    for (int i = 1; i <= n; ++i) {
        cin >> st.a[i];
    }
    st.build(1, n, 1);
    while (m--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll x, y, k;
            cin >> x >> y >> k;
            st.update(x, y, k, 1, n, 1);
        } else {
            ll x, y;
            cin >> x >> y;
            cout << st.get_sum(x, y, 1, n, 1) << "\n";
        }
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}