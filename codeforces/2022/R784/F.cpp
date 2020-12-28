#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<ll> pre(n + 1);
    pre[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    vector<ll> suf(n + 1);
    suf[n] = 0;
    for (ll i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    reverse(suf.begin(), suf.end());
    ll ans = 0;
    for (ll i = 0; i <= n; ++i) {
        auto cnt = pre[i] - pre[0];
        auto pos = lower_bound(suf.begin(), suf.end(), cnt);
        if (pos == suf.end() || *pos != cnt) {
            continue;
        }
        if (pos - suf.begin() + i > n) {
            continue;
        }
        ans = max(ans, i + (pos - suf.begin()));
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}