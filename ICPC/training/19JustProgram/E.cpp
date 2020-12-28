#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    string s, c, p;
    cin >> s >> c >> p;
    array<ll, 26> mp;
    mp.fill(-1);
    for (ll i = 0; i < n; ++i) {
        if (mp[s[i] - 'a'] == -1) {
            mp[s[i] - 'a'] = c[i] - '0';
        } else {
            mp[s[i] - 'a'] = min(c[i] - '0' + 0LL, mp[s[i] - 'a']);
        }
    }
    ll ans = 0;
    for (auto i : p) {
        if (mp[i - 'a'] == -1) {
            cout << "-1\n";
            return;
        }
        ans += mp[i - 'a'];
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