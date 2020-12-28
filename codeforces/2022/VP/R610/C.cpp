#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, T, a, b;
    cin >> n >> T >> a >> b;
    vector<ll> s(n);
    ll simple = 0, hard = 0;
    for (auto &i : s) {
        cin >> i;
        if (i == 0) {
            simple++;
        } else {
            hard++;
        }
    }
    vector<ll> t(n + 1);
    for (ll i = 0; i < n; ++i) {
        cin >> t[i];
    }
    t[n] = T + 1;
    vector<ll> id(n + 1);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](auto x, auto y) { return t[x] < t[y]; });
    ll sum = 0, ans = 0, pre = 0, num = 0;
    for (auto i : id) {
        auto T = t[i] - 1;
        if (i == n) {
            if (T >= pre) {
                cout << n << "\n";
                return;
            }
            break;
        }
        if (T >= pre) {
            auto res = T - pre;
            ll mi = min(simple, res / a);
            res -= mi * a;
            ll ma = min(hard, res / b);
            ans = max(ans, num + mi + ma);
        }
        if (s[i] == 0) {
            simple--;
            pre += a;
        } else {
            hard--;
            pre += b;
        }
        num++;
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