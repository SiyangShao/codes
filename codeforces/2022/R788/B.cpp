#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll k;
    cin >> k;
    unordered_map<char, ll> mp;
    mp.clear();
    for (int i = 0; i < k; ++i) {
        char tmp;
        cin >> tmp;
        mp[tmp] = 1;
    }
    ll cnt = 0, ans = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (mp[s[i]]) {
            if (!flag) {
                flag = true;
                ans = cnt;
            } else {
                ans = max(ans, cnt + 1);
            }
            cnt = 0;
        } else {
            cnt++;
        }
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