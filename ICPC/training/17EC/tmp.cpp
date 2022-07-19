#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    if (n % 2 == 1 && n >= 7) {
        cout << "Panda\n";
    } else if (n <= 15) {
        cout << "Draw\n";
    } else {
        cout << "Sheep\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    ll t = 1;
    while (_--) {
        cout << "Case #" << t << ": ";
        t++;
        solve();
    }
}