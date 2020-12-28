#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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
    auto mi = *min_element(a.begin(), a.end());
    auto mn = min({abs(mi - 1) * 2, abs(a[0] - 1), abs(a[n - 1] - 1)});
    cnt += mn;
    auto mx = *max_element(a.begin(), a.end());
    if (mx < x) {
        mn = min({abs(x - mx) * 2, abs(x - a[0]), abs(x - a[n - 1])});
        cnt += mn;
    }
    cout << cnt << "\n";
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