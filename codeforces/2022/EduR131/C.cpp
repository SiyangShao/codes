#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> wrk(n);
    wrk.assign(n, 0);
    for (auto &i : a) {
        cin >> i;
        i--;
        wrk[i]++;
    }
    function<bool(ll)> check = [&](ll t) {
        ll work = 0, time = 0;
        for (auto i : wrk) {
            if (i > t) {
                work += (i - t);
            }
            if (i < t) {
                time += (t - i) / 2;
            }
        }
        return time >= work;
    };
    ll L = 1, R = *max_element(wrk.begin(), wrk.end());
    ll ans = R;
    while (L <= R) {
        ll mid = (L + R) / 2;
        if (check(mid)) {
            R = mid - 1;
            ans = min(ans, mid);
        } else {
            L = mid + 1;
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