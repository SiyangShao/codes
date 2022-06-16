#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    string s;
    cin >> n >> s;
    ll ans = 1;
    for (ll i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            ans++;
        } else {
            ans += i + 1;
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