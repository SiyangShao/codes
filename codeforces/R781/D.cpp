#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto guess(auto x, auto y) {
    cout << "? " << x << " " << x + y << endl;
    ll ans;
    cin >> ans;
    return ans;
}
auto output(auto x) { cout << "! " << x << endl; }
auto solve() {
    ll cur = 1, ans = 0;
    for (ll i = 0; i < 30; ++i) {
        ll x = guess(cur - ans, cur * 2);
        if (x == cur * 2) {
            ans += cur;
        }
        cur *= 2;
    }
    output(ans);
}
auto main() -> int {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}