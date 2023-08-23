#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    unordered_map<char, ll> mp;
    mp.clear();
    for (ll i = 0; i < 26; ++i) {
        mp[s[i]] = i;
    }
    ll n;
    cin >> n;
    vector<string> str(n);
    for (auto &i : str) {
        cin >> i;
    }
    sort(str.begin(), str.end(), [&](auto x, auto y) {
        ll X = x.length(), Y = y.length();
        for (ll i = 0; i < min(X, Y); ++i) {
            if (mp[x[i]] != mp[y[i]]) {
                return mp[x[i]] < mp[y[i]];
            }
        }
        return X < Y;
    });
    ll k;
    cin >> k;
    cout << str[k - 1] << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}