#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    map<string, ll> mp;
    ll cnt = 0;
    bool flag = false;
    vector<vector<ll>> dic(10);
    while (n--) {
        string L, R;
        cin >> L >> R;
        if (mp.find(L) == mp.end()) {
            mp[L] = cnt;
            cnt++;
        }
        if (mp.find(R) == mp.end()) {
            mp[R] = cnt;
            cnt++;
        }
        dic[mp[L]].emplace_back(mp[R]);
    }
    for (ll i = 0; i < 10; ++i) {
        if (dic[i].size() < 5) {
            continue;
        }
        set<ll> tmp;
        for (ll j = 0; j + 5 <= dic[i].size(); ++j) {
            tmp.clear();
            for (ll k = 0; k < 5; ++k) {
                tmp.emplace(dic[i][j + k]);
            }
            if (tmp.size() == 5) {
                cout << "PENTA KILL!\n";
                return;
            }
        }
    }
    cout << "SAD:(\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--) {
        solve();
    }
}