#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll MIN = 1e9 + 7, MAX = -(1e9 + 7);
    for (auto &i : a) {
        cin >> i;
        MIN = min(MIN, i);
        MAX = max(MAX, i);
    }
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }
    if (MIN <= 0 && MAX >= 0) {
        ll ans = 0;
        for (auto &i : a) {
            ans += abs(i);
        }
        cout << ans << "\n";
    } else {
        ll ans = 0, cnt = 0;
        for (auto &i : a) {
            i = abs(i);
            ans += i;
        }
        cnt = ans;
        cnt -= a[0] * 2;
        for (auto &i : a) {
            cnt = max(cnt, ans - i * 2);
        }
        cout << cnt << "\n";
    }
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