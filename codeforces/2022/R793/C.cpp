#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    mp.clear();
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
    }
    ll single = 0, over = 0;
    for (auto &[_, num] : mp) {
        if (num == 1) {
            single++;
        } else {
            over++;
        }
    }
    ll s = 0, o = 0, ans = 0;
    for (auto &[i, num] : mp) {
        if (num == 1) {
            single--;
        } else {
            over--;
        }
        ans = max(ans, 1 + (single + s) / 2 + over + o);
        if (num == 1) {
            s++;
        } else {
            o++;
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