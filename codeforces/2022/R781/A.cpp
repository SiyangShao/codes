#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    if (n % 2 == 1) {
        n -= 2;
        cout << n / 2 << " " << n / 2 + 1 << " "
             << "1 1"
             << "\n";
    } else {
        if (n % 4 == 0) {
            n /= 4;
            cout << n << " " << n << " " << n << " " << n << "\n";
        } else {
            n -= 2;
            n /= 2;
            cout << n - 1 << " " << n + 1 << " "
                 << "1 1\n";
        }
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