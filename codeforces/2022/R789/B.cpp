#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 1, ans = 0;
    auto pre = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] == pre) {
            cnt++;
        } else {
            if (cnt % 2 == 0) {
                cnt = 1;
                pre = s[i];
            } else {
                ans++;
                cnt = 2;
                pre = s[i];
            }
        }
    }
    assert(cnt % 2 == 0);
    cout << ans << "\n";
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