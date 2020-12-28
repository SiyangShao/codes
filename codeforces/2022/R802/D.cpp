#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> v(n), t(n), pre(n + 1);
    for (auto &i : v) {
        cin >> i;
    }
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + v[i];
    ll mini = 0;
    auto need = [&](ll i, ll end) {
        ll l = mini, r = 1e16;
        auto check = [&](ll mid) { return i128(mid) * (i + 1) >= pre[end]; };
        while (l < r) {
            ll mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    };
    for (ll i = 0; i < n; ++i) {
        mini = max(mini, need(i, i + 1));
        t[i] = -need(i, n);
    }
    ll Q;
    cin >> Q;
    while (Q--) {
        ll T;
        cin >> T;
        auto pos = lower_bound(t.begin(), t.end(), -T);
        if (pos == t.end()) {
            cout << "-1\n";
        } else {
            cout << pos - t.begin() + 1 << "\n";
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