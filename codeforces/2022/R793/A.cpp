#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    string s;
    cin >> n >> s;
    ll cnt = 0;
    for (auto i = (n - 1) / 2; i >= 0; --i) {
        if (s[i] == s[(n - 1) / 2]) {
            cnt++;
        } else {
            break;
        }
    }
    cout << cnt * 2 - (n % 2 == 1 ? 1 : 0) << "\n";
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