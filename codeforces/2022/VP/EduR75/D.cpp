#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, s;
    cin >> n >> s;
    assert(n % 2 == 1);
    vector<pair<ll, ll>> a(n);
    for (auto &[l, r] : a) {
        cin >> l >> r;
    }
    sort(a.begin(), a.end());
    auto check = [&](ll m) {
        ll sum = 0, ndr = n / 2 + 1;
        vector<ll> v;
        v.clear();
        for (const auto &[l, r] : a) {
            if (r < m) {
                sum += l;
            } else if (l >= m) {
                sum += l;
                ndr--;
            } else {
                v.emplace_back(l);
            }
        }
        ndr = max(ndr, 0LL);
        if (ndr > v.size()) {
            return false;
        }
        for (ll i = 0; i < v.size(); ++i) {
            if (i < v.size() - ndr) {
                sum += v[i];
            } else {
                sum += m;
            }
        }
        return sum <= s;
    };
    ll L = 0, R = 1e10;
    ll ans = L;
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