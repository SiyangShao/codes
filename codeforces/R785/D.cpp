#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
auto solve() {
    ll b, q, y, c, r, z;
    cin >> b >> q >> y >> c >> r >> z;
    if (r % q != 0) {
        cout << "0\n";
        return;
    }
    if (c < b || c + r * (z - 1) > b + q * (y - 1) || (c - b) % q != 0) {
        cout << "0\n";
        return;
    }
    if (c + r * z > b + q * (y - 1) || c - r < b) {
        cout << "-1\n";
        return;
    }
    // ll cnt = 0;
    // for (int i = 1; i <= q; ++i) {
    //     if (q % i == 0) {
    //         cnt = cnt + i * i;
    //         cnt %= MOD;
    //         if (i > sqrt(q)) {
    //             cout << i << " ";
    //         }
    //     }
    // }
    // cout << cnt << "\n";
    ll cnt = 0, base = r / q;
    for (int i = 1; i * i <= q; ++i) {
        if (q % i == 0) {
            auto res = q / i;
            if (lcm(res * base, q) == r)
                cnt = (cnt + i * i) % MOD;
            if (i != res) {
                if (lcm(i * base, q) == r)
                    cnt = (cnt + res * res) % MOD;
            }
        }
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