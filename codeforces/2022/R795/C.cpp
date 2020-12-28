#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    ll n, k;
    cin >> n >> k >> s;
    ll flag = -1;
    for (ll i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            flag = i;
            break;
        }
    }
    if (flag != -1 && flag != n - 1 && abs(flag - (n - 1)) <= k) {
        k -= abs(flag - (n - 1));
        swap(s[flag], s[n - 1]);
    }
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '1') {
            flag = i;
            break;
        }
    }
    if (flag != -1 && flag != n - 1 && flag != 0 && abs(flag - 0) <= k) {
        swap(s[0], s[flag]);
    }
    ll ans = 0;
    for (ll i = 0; i + 1 < n; ++i) {
        ans += 10LL * (s[i] - '0');
        ans += s[i + 1] - '0';
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