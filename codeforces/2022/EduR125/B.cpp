#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, B, x, y;
    cin >> n >> B >> x >> y;
    ll ans = 0, res = 0;
    for (int i = 0; i <= n; ++i) {
        res += ans;
        // cout << ans << " ";
        if (ans + x <= B) {
            ans += x;
        } else {
            ans -= y;
        }
    }
    cout << res << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_-- != 0) {
        solve();
    }
}