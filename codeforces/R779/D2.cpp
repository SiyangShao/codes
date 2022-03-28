#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto cal(ll l, ll r, vector<ll> &a) -> ll {
    unordered_map<ll, ll> mp;
    if (l % 2 == 0 && r % 2 == 1) {
        for (auto i : a) {
            mp[i / 2] = 1;
        }
        vector<ll> nxt;
        for (auto &&[k, v] : mp) {
            if (v == 1) {
                nxt.push_back(k);
            }
        }
        return cal(l / 2, r / 2, nxt) * 2;
    }
    for (auto i : a) {
        mp[i] = 1;
    }
    vector<ll> ans;
    for (auto i : a) {
        if (mp[i ^ 1] == 0) {
            ans.emplace_back(i ^ l);
            ans.emplace_back(i ^ r);
        }
    }
    for (auto x : ans) {
        bool flag = true;
        for (ll i = l; i <= r; ++i) {
            if (mp[i ^ x] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return x;
        }
    }
    return 0;
}
auto solve() {
    ll l, r;
    cin >> l >> r;
    vector<ll> a(r - l + 1);
    for (auto &i : a) {
        cin >> i;
    }
    cout << cal(l, r, a) << "\n";
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