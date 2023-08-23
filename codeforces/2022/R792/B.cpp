#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll z = c;
    ll y = z + b;
    ll x = y + a;
    assert(x % y == a && y % z == b && z % x == c);
    cout << x << " " << y << " " << z << "\n";
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