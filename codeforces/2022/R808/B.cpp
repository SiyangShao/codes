#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
    }
    function<ll()> dfs = [&]() {
        if (mp.size() == 1) {
            if (mp.begin()->second > 1) {
                return 0LL;
            }
            return mp.begin()->first;
        }
        map<ll, ll> new_mp;
        for (auto i = mp.begin(); i != mp.end(); ++i) {
            if (i->second > 1) {
                new_mp[0] += i->second - 1;
            }
            auto nxt = i;
            nxt++;
            if (nxt != mp.end()) {
                new_mp[nxt->first - i->first]++;
            }
        }
        mp = move(new_mp);
        return dfs();
    };
    cout << dfs() << "\n";
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