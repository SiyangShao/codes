#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto ask(ll i) {
    cout << "? " << i << endl;
    ll tmp;
    cin >> tmp;
    return tmp;
}
auto solve() {
    ll n;
    cin >> n;
    ll l = n, r = n * 2000 + n;
    auto mid = (l + r) / 2;
    while (l <= r) {
        mid = (l + r) / 2;
        auto k = ask(mid);
        if (k == 1) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    auto cnt = l;
    for (int i = 2; i <= n; ++i) {
        ll tmp = l / i;
        auto k = ask(tmp);
        if (k != 0)
            cnt = min(cnt, tmp * k);
        else
            break;
    }
    cout << "! " << cnt << endl;
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