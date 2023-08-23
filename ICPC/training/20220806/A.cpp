#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a;
    cin >> a;
    auto tmp = a;
    ll cnt = 0;
    while (tmp) {
        cnt += tmp % 10;
        tmp /= 10;
    }
    cout << a * cnt << "\n";
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