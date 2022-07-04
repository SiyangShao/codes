#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    string s1 = "0110", s2 = "1001";
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (i % 4 == 0 || i % 4 == 3) {
                cout << s1[j % 4];
            } else {
                cout << s2[j % 4];
            }
            cout << " ";
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