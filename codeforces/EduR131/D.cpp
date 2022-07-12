#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node {
    ll L, R;
    ll id;
};
auto solve() {
    ll n;
    cin >> n;
    vector<ll> b(n), vis(n + 1), ans(n);
    vector<node> range(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
        vis[i + 1] = 0;
        ll L, R;
        L = (i + 1) / (b[i] + 1);
        if (b[i] == 0) {
            R = n;
        } else {
            R = (i + 1) / b[i];
        }
        range[i].L = L + 1, range[i].R = R;
        range[i].id = i;
    }
    sort(range.begin(), range.end(), [&](auto l, auto r) {
        if (l.R != r.R) {
            return l.R < r.R;
        } else {
            return l.L < r.L;
        }
    });
    multiset<ll> an;
    for (ll i = 1; i <= n; ++i) {
        an.emplace(i);
    }
    for (ll j = 0; j < n; ++j) {
        auto which = an.lower_bound(range[j].L);
        if (which != an.end() && *which <= range[j].R) {
            ans[range[j].id] = *which;
            an.erase(which);
        }
    }
    for (auto j : ans) {
        cout << j << " ";
    }
    cout << "\n";
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