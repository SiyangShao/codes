#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    vector<ll> mp(26, 0);
    vector<bool> can(26, false);
    for (ll i = 0; i < s.length(); ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            if (mp[s[i] - 'a'] % 2 == 1) {
                can[s[i] - 'a'] = true;
            }
            mp[s[i] - 'a'] = 0;
        }
        mp[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (mp[i] % 2 == 1) {
            can[i] = true;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (can[i]) {
            cout << char(i + 'a');
        }
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