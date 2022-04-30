#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
constexpr ll MOD = 1e9 + 7;
auto solve() {
    ll b, q, y, c, r, z;
    cin >> b >> q >> y >> c >> r >> z;
    if (r % q != 0) {
        cout << "0\n";
        return;
    }
    i128 B = b, Q = q, Y = y, C = c, R = r, Z = z;
    if (C < B || C + R * (Z - 1) > B + Q * (Y - 1) || (C - B) % q != 0) {
        cout << "0\n";
        return;
    }
    if (C + R * Z > B + Q * (Y - 1) || C - R < B) {
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
    ll cnt = 0;
    for (int i = 1; i <= sqrt(q); ++i) {
        if (q % i == 0) {
            cnt = (cnt + (i * i) % MOD) % MOD;
            auto res = q / i;
            if (res != i) {
                cnt = (cnt + (res * res) % MOD) % MOD;
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