#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, L;
    cin >> n >> L;
    vector<ll> a(n), b(n);
    for (auto &i : a) {
        cin >> i;
        i += L;
    }
    for (auto &i : b) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n * 3; ++i) {
        a.emplace_back(a[i] + L);
        b.emplace_back(b[i] + L);
    }
    function<bool(ll)> check = [&](ll x) {
        ll mx = -1e9;
        for (int i = 0; i < n * 2; ++i) {
            ll l = lower_bound(b.begin(), b.end(), a[i] - x) - b.begin() + 1;
            ll r = upper_bound(b.begin(), b.end(), a[i] + x) - b.begin();
            mx = max(mx, l - i);
            if (mx > r - i) {
                return false;
            }
        }
        return true;
    };
    ll l = 0, r = L;
    ll ans = L;
    while (l <= r) {
        auto mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = min(ans, mid);
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
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