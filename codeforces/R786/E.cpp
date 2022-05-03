#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2e6 + 7;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll fi = N, se = N;
    for (auto &i : a) {
        cin >> i;
        if (i < fi) {
            se = fi;
            fi = i;
        } else {
            se = min(se, i);
        }
    }
    ll res = (fi + 1) / 2 + (se + 1) / 2;
    for (int i = 0; i + 1 < n; ++i) {
        res = min(res, max(max((a[i] + 1) / 2, (a[i + 1] + 1) / 2),
                           (a[i] + a[i + 1] + 2) / 3));
    }
    for (int i = 1; i + 1 < n; ++i) {
        res = min(res,
                  min(a[i - 1], a[i + 1]) + (abs(a[i + 1] - a[i - 1]) + 1) / 2);
    }
    cout << res << "\n";
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