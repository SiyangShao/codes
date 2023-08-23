#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    vector<ll> mp;
    mp.assign(26, 0);
    ll cnt = 0;
    for (auto i : s) {
        if (mp[i - 'a'] == 0) {
            cnt++;
        }
        mp[i - 'a']++;
    }
    mp.assign(26, 0);
    for (int i = 0; i < cnt; ++i) {
        mp[s[i] - 'a']++;
        if (mp[s[i] - 'a'] > 1) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = cnt; i < s.length(); ++i) {
        mp[s[i - cnt] - 'a']--;
        mp[s[i] - 'a']++;
        if (mp[s[i] - 'a'] > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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