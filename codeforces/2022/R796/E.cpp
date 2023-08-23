#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    vector<ll> vis, val(m + 1);
    val[0] = -1;
    for (ll i = 1; i <= m; ++i) {
        cout << "? ";
        for (ll j = 1; j <= m; ++j) {
            if (j == i) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
        cin >> val[i];
    }
    vis.assign(m + 1, 0);
    vector<ll> pos(m + 1);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.begin(), pos.end(),
         [&](auto x, auto y) { return val[x] < val[y]; });
    for (ll i = 1; i <= m; ++i) {
        cout << "? ";
        vis[pos[i]] = 1;
        for (ll j = 1; j <= m; ++j) {
            cout << vis[j];
        }
        cout << endl;
        ll tmp;
        cin >> tmp;
        if (tmp == ans + val[pos[i]]) {
            ans += val[pos[i]];
        } else {
            vis[pos[i]] = 0;
        }
    }
    cout << "! " << ans << endl;
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