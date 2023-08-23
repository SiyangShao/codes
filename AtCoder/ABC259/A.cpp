#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;
    T -= X * D;
    if (M <= X) {
        cout << T + M * D << "\n";
    } else {
        cout << T + X * D << "\n";
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