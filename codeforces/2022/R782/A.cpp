#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, r, b;
    cin >> n >> r >> b;
    auto p = r / (b + 1);
    auto q = r % (b + 1);
    for (int i = 0; i < b + 1; i++) {
        for (int i = 0; i < p; i++)
            cout << "R";
        if (q > 0)
            cout << "R";
        q--;
        if (i != b)
            cout << "B";
    }
    cout << "\n";
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