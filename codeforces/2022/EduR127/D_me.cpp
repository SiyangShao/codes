#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    ll cnt = 0;
    for (int i = 1; i < n; ++i) {
        cnt += abs(a[i] - a[i - 1]);
    }
    // cout << cnt << " ";
    if (x == 1) {
        ll ans = cnt + min(abs(a[0] - 1), abs(a[n - 1] - 1));
        for (int i = 1; i < n; ++i) {
            ans = min(ans, cnt - abs(a[i] - a[i - 1]) + abs(a[i] - 1) +
                               abs(a[i - 1] - 1));
        }
        cout << ans << "\n";
        return;
    }
    vector<pair<ll, ll>> MIN, MAX;
    MIN.clear(), MAX.clear();
    MIN.emplace_back(abs(1 - a[0]), 0);
    MAX.emplace_back(abs(x - a[0]), 0);
    MIN.emplace_back(abs(1 - a[n - 1]), n);
    MAX.emplace_back(abs(x - a[n - 1]), n);
    for (int i = 1; i < n; ++i) {
        auto tmp = abs(1 - a[i]) + abs(1 - a[i - 1]) - abs(a[i] - a[i - 1]);
        MIN.emplace_back(tmp, i);
        tmp = abs(x - a[i]) + abs(x - a[i - 1]) - abs(a[i] - a[i - 1]);
        MAX.emplace_back(tmp, i);
    }
    sort(MIN.begin(), MIN.end(),
         [](auto x, auto y) { return x.first < y.first; });
    sort(MAX.begin(), MAX.end(),
         [](auto x, auto y) { return x.first < y.first; });
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < min(n + 1, 16LL); ++i) {
        for (int j = 0; j < min(n + 1, 16LL); ++j) {
            if (MIN[i].second != MAX[j].second) {
                ans = min(ans, cnt + MIN[i].first + MAX[j].first);
            } else {
                if (MIN[i].second == 0 || MIN[i].second == n) {
                    ans = min(ans, cnt + min(MIN[i].first, MAX[j].first) +
                                       abs(x - 1));
                    // cout << "CA " << ans << "\n";
                } else {
                    auto pos = MIN[i].second;
                    ans = min(ans,
                              cnt - abs(a[pos] - a[pos - 1]) +
                                  min(abs(1 - a[pos]) + abs(x - a[pos - 1]),
                                      abs(1 - a[pos - 1]) + abs(x - a[pos])) +
                                  x - 1);
                }
            }
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