#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> h(n), p(m);
    for (auto &i : h) {
        cin >> i;
    }
    for (auto &i : p) {
        cin >> i;
    }
    function<bool(ll)> check = [&](ll d) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (p[cur] >= h[i]) {
                while (p[cur] - h[i] <= d) {
                    cur++;
                    if (cur == m) {
                        return true;
                    }
                }
            } else {
                if (h[i] - p[cur] > d) {
                    return false;
                }
                auto nxt = p[cur] + d - (h[i] - p[cur]);
                auto nxt2 = (d - (h[i] - p[cur])) / 2 + h[i];
                nxt = max(nxt, h[i]);
                nxt = max(nxt, nxt2);
                auto nxt_cur = upper_bound(p.begin(), p.end(), nxt) - p.begin();
                if (nxt_cur == m) {
                    return true;
                }
                cur = nxt_cur;
            }
        }
        return cur == m;
    };
    ll L = 0, R = abs(h[0] - p[0]) + abs(p[m - 1] - p[0]);
    ll ans = R;
    while (L <= R) {
        auto mid = (L + R) / 2;
        if (check(mid)) {
            ans = min(ans, mid);
            R = mid - 1;
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
    // cin >> _;
    while (_--) {
        solve();
    }
}
