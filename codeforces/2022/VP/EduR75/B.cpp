#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<string> mp(n);
    ll zero = 0, one = 0;
    ll odd = 0, even = 0, ans = 0;
    for (auto &i : mp) {
        cin >> i;
        if (i.length() % 2 == 1) {
            ans++;
            odd++;
            continue;
        }
        zero = one = 0;
        for (auto j : i) {
            if (j == '0') {
                zero++;
            } else {
                one++;
            }
        }
        if (zero % 2 == 0 && one % 2 == 0) {
            ans++;
            continue;
        }
        even++;
    }
    if (odd) {
        ans += even;
        even = 0;
    }
    if (even % 2 == 1) {
        ans += even - 1;
    } else {
        ans += even;
    }
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