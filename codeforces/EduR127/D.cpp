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
    ll mn = min(a[0] - 1, a[n - 1] - 1);
    for (int i = 0; i < n; ++i) {
        mn = min(mn, 2 * (a[i] - 1));
    }
    cnt += mn;
    auto mx = *max_element(a.begin(), a.end());
    if (mx < x) {
        mn = min(x - a[0], x - a[n - 1]);
        for (int i = 0; i < n; ++i) {
            mn = min(mn, 2 * (x - a[i]));
        }
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