#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    auto res = min(a, b) * 2 + c * 2;
    if (a != b) {
        res++;
    }
    cout << res << "\n";
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