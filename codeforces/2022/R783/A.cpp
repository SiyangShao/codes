#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    if (n == m) {
        cout << n - 1 + m - 1 << "\n";
    } else {
        if (n > m)
            swap(n, m);
        if (n == 1) {
            if (m == 2)
                cout << 1 << "\n";
            else
                cout << "-1\n";
            return;
        }
        m = m - n + 1;
        auto res = (n - 1) * 2;
        res += m / 2 + ((m - 1) / 2) * 3;
        cout << res << "\n";
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