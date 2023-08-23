#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    array<ll, 3> a;
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    if (a[2] >= a[0] + a[1]) {
        cout << a[0] + a[1] << "\n";
    } else {
        cout << (a[0] + a[1] + a[2]) / 2 << "\n";
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