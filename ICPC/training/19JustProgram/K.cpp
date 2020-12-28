#include <bits/stdc++.h>
#include <limits>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    set<ll> ans, pre, cur;
    ans.clear(), pre.clear(), cur.clear();
    for (auto i : a) {
        cur.insert(i);
        for (auto it : pre) {
            cur.insert(it | i);
        }
        for (auto it : cur) {
            ans.insert(it);
        }
        pre = move(cur);
        cur.clear();
    }
    cout << ans.size() << "\n";
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