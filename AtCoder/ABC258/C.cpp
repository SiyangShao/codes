#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, q;
    string s;
    cin >> n >> q >> s;
    ll beg = 0;
    while (q--) {
        ll t, x;
        cin >> t >> x;
        if (t == 1) {
            beg += x;
            beg %= n;
        } else {
            x--;
            if (x >= beg) {
                x -= beg;
                cout << s[x] << "\n";
            } else {
                x = x + n - beg;
                cout << s[x] << "\n";
            }
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