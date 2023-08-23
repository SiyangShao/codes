#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "1\n1\n";
    } else if (n == 2) {
        cout << "2\n2 2\n";
    } else {
        cout << (n - 2) * 2 << "\n";
        for (ll i = 2; i < n; ++i) {
            cout << i << " ";
        }
        for (ll i = n - 1; i >= 2; --i) {
            cout << i << " \n"[i == 2];
        }
    }
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