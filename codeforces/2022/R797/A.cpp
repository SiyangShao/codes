#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    ll tmp = n / 3;
    if (n % 3 == 0) {
        cout << tmp << " " << tmp + 1 << " " << tmp - 1 << "\n";
    } else if (n % 3 == 1) {
        cout << tmp << " " << tmp + 2 << " " << tmp - 1 << "\n";
    } else {
        cout << tmp + 1 << " " << tmp + 2 << " " << tmp - 1 << "\n";
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