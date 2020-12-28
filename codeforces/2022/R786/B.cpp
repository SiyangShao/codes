#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
unordered_map<string, ll> mp;
auto init() {
    ll cnt = 1;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i == j)
                continue;
            string tmp = "aa";
            tmp[0] += i, tmp[1] += j;
            mp[tmp] = cnt;
            cnt++;
        }
    }
}
auto solve() {
    string s;
    cin >> s;
    cout << mp[s] << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    init();
    cin >> _;
    while (_--) {
        solve();
    }
}