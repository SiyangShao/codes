#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16 + 7;
auto solve() {
    ll n, m;
    cin >> n >> m;
    ll ans = (1 + m) * m / 2;
    ans += (1 + n) * n / 2 * m;
    ans -= m;
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