#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    if (n % 2 == 1 || n < 4) {
        cout << "-1\n";
        return;
    }
    n /= 2;
    ll three = n / 3;
    if ((n - three * 3) % 2 == 0) {
        cout << three + (n - three * 3) / 2;
    } else {
        three--;
        cout << three + (n - three * 3) / 2;
    }
    cout << " ";
    ll two = n / 2;
    cout << two << "\n";
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