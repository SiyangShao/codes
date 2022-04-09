#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
vector<pair<ll, ll>> t;
vector<ll> a;

auto get(auto v, auto vl, auto vr, auto l, auto r) -> pair<ll, ll> {
    if (vl >= l && vr <= r)
        return t[v];
    if (r <= vl || l >= vr)
        return {INT_MAX, INT_MAX};
    int vm = (vl + vr) / 2;
    return min(get(2 * v + 1, vl, vm, l, r), get(2 * v + 2, vm, vr, l, r));
}

auto mod(auto v, auto vl, auto vr, auto id, auto val) {
    if (vr - vl == 1) {
        t[v] = make_pair(val, id);
        return;
    }
    int vm = (vl + vr) / 2;
    if (id < vm)
        mod(2 * v + 1, vl, vm, id, val);
    else
        mod(2 * v + 2, vm, vr, id, val);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}
auto solve() {
    ll n;
    cin >> n;
    a.resize(n);
    for (auto &i : a)
        cin >> i;
    t.resize(4 * n);
    for (auto i = 0; i < n; ++i) {
        mod(0, 0, n, i, a[i]);
    }
    ll q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--;
        vector<pair<ll, ll>> ans;
        for (auto i = 0; i < min(r - l, 31LL); ++i) {
            auto now = get(0, 0, n, l, r);
            ans.emplace_back(now);
            mod(0, 0, n, now.second, INT_MAX);
        }
        ll cnt = INT_MAX;
        for (auto i = ans.begin(); i < ans.end(); ++i) {
            for (auto j = i + 1; j < ans.end(); ++j) {
                cnt = min(cnt, i->first | j->first);
            }
        }
        for (auto &c : ans) {
            mod(0, 0, n, c.second, c.first);
        }
        cout << cnt << "\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
}