#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<string> s(2 * n);
    vector<ll> ch(26);
    ch.assign(26, 0);
    for (auto &i : s) {
        cin >> i;
        for (auto &j : i) {
            ch[j - 'a']++;
        }
    }
    string final;
    cin >> final;
    for (auto &j : final) {
        ch[j - 'a']++;
    }
    for (ll i = 0; i < 26; ++i) {
        if (ch[i] % 2 == 1) {
            cout << char(i + 'a') << "\n";
            return;
        }
    }
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