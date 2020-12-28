#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
auto solve() {
    int n, s;
    cin >> n >> s;
    vector<pair<ll, ll>> a(n);
    for (auto &[l, r] : a) {
        cin >> r;
        r--;
    }
    vector<bool> vis(n, false);
    for (auto &[l, r] : a) {
        cin >> l;
        if (l != -1) {
            l--;
            vis[l] = true;
        }
    }
    vector<ll> missing;
    for (ll i = 0; i < n; ++i) {
        if (!vis[i]) {
            missing.emplace_back(i);
        }
    }
    sort(a.begin(), a.end(), greater<>());
    ll mx = 0;
    for (auto &[l, r] : a) {
        if (l != -1) {
            mx = max(mx, r - l);
        }
    }
    if (mx > s) {
        cout << "0\n";
        return;
    }
    vector<ll> cnt;
    for (ll i = 0; i < n; ++i) {
        if (a[i].first == -1) {
            cnt.emplace_back(missing.end() - lower_bound(missing.begin(),
                                                         missing.end(),
                                                         a[i].second - s));
        }
    }
    sort(cnt.begin(), cnt.end());
    ll res = 1;
    for (ll i = 0; i < cnt.size(); ++i) {
        res = res * (cnt[i] - i) % MOD;
    }
    cout << res << "\n";
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
