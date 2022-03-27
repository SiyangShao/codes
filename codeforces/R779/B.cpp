#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
auto solve() {
    ll n;
    cin >> n;
    if (n % 2 == 1) {
        cout << "0\n";
    } else {
        n /= 2;
        ll cnt = 1;
        for (ll i = 1; i <= n; ++i) {
            cnt = cnt * i % MOD;
        }
        cnt = cnt * cnt % MOD;
        cout << cnt << "\n";
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