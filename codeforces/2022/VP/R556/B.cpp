#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<string> mp(n);
    for (auto &i : mp) {
        cin >> i;
    }
    for (ll i = 1; i + 1 < n; ++i) {
        for (ll j = 1; j + 1 < n; ++j) {
            if (mp[i][j] == '.' && mp[i - 1][j] == '.' && mp[i + 1][j] == '.' &&
                mp[i][j - 1] == '.' && mp[i][j + 1] == '.') {
                mp[i][j] = '#';
                mp[i - 1][j] = '#';
                mp[i + 1][j] = '#';
                mp[i][j + 1] = '#';
                mp[i][j - 1] = '#';
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (mp[i][j] == '.') {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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