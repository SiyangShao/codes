#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;

    if (n % 2 == 1) {
        cout << "1";
        for (ll i = 2; i < n; i += 2) {
            cout << " " << i + 1 << " " << i;
        }
        cout << "\n";
    } else {
        for (ll i = 1; i < n; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
        cout << "\n";
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