#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * @brief
 * Suppose we have pre elements before value x, thus we need to buy more than x
 * - pre elements in order to have *all* the elements. Obviously, they should be
 * as cheaper as possible. Thus, we can use greedy to solve the problem.
 * @return auto
 */
auto solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    vector<vector<ll>> v(n);
    for (auto &[m, p] : a) {
        cin >> m >> p;
        v[m].emplace_back(p);
    }
    multiset<ll> q;
    ll res = 0, pre = n, cnt = 0;
    for (ll i = n - 1; i >= 0; --i) {
        pre -= v[i].size();
        auto need = i - pre;
        for (auto x : v[i]) {
            q.emplace(x);
        }
        while (cnt < need) {
            cnt++;
            res += *q.begin();
            q.erase(q.begin());
        }
    }
    cout << res << "\n";
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