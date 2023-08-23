#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    string s;
    cin >> n >> s;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (i > 0 && s[i - 1] == '0') {
                cnt += 2;
            } else if (i > 1 && s[i - 2] == '0') {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
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