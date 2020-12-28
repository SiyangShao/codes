#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    assert(a == 1 && b == 1);
    ll cnt = gcd(x, y);
    x /= cnt, y /= cnt;
    ll tmp = x + y, ans = 0;
    while (tmp % 2 == 0) {
        tmp /= 2;
        ans++;
    }
    if (tmp != 1 || x % 2 == 0 || y % 2 == 0) {
        cout << "-1\n";
        return;
    } else {
        cout << ans + 1 << "\n";
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