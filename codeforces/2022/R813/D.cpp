#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e9;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    // observation: d(u,v) = min(min(a_u - a_v),  a_min * 2)
    // if we set a[u] = x, x must be inf
    for (auto &i : a) {
        cin >> i;
    }
    function<bool(ll)> check = [&](ll d) {
        auto b = a;
        ll op = 0;
        for (auto &i : b) {
            if (i * 2 < d) {
                i = inf;
                op++;
            }
        }
        if (op > k) {
            return false;
        }
        ll mx = 0;
        for (ll i = 0; i + 1 < n; ++i) {
            if (min(b[i], b[i + 1]) >= d) {
                return true;
            }
            mx = max(mx, b[i]);
            mx = max(mx, b[i + 1]);
        }
        if (mx >= d) {
            return (k - op) >= 1;
        } else {
            return (k - op) >= 2;
        }
    };
    ll L = 1, R = inf;
    ll ans = 1;
    while (L <= R) {
        ll mid = (L + R) / 2;
        if (check(mid)) {
            ans = max(ans, mid);
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    cout << ans << "\n";
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