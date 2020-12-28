#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector<ll> a(n);
    vector<ll> b(m);
    for (auto &i : a) {
        cin >> i;
        i += ta;
    }
    for (auto &i : b) {
        cin >> i;
    }
    if (k >= n || k >= m) {
        cout << "-1\n";
        return;
    }
    ll ans = 0;
    for (auto i = 0; i <= k; ++i) {
        auto j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (j + k - i >= m) {
            cout << "-1\n";
            return;
        }
        ans = max(ans, b[j + k - i]);
    }
    cout << ans + tb << "\n";
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