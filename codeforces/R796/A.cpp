#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll x;
    cin >> x;
    ll cnt = 0, bs = 1, same = x;
    while (x) {
        if (x % 2 == 1) {
            cnt += bs;
            break;
        }
        bs *= 2;
        x /= 2;
    }
    if (same % 2 == 1) {
        if (same == 1) {
            cnt += 2;
        }
    } else {
        if (cnt == same)
            cnt++;
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