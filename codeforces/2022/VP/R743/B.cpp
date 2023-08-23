#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a.begin(), a.end(), [](auto x, auto y) { return x.first < y.first; });
    sort(b.begin(), b.end(), [](auto x, auto y) { return x.first < y.first; });
    auto res = a[0].second, ans = a[0].second + b[0].second;
    for (int i = 1; i < n; ++i) {
        res = min(res, a[i].second);
        ans = min(ans, res + b[i].second);
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