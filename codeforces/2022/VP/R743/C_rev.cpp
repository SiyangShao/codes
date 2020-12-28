#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> in(n);
    vector<vector<ll>> E;
    E.assign(n, vector<ll>());
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
    while (!q.empty())
        q.pop();
    for (ll i = 0; i < n; ++i) {
        cin >> in[i];
        if (in[i] == 0) {
            q.emplace(1LL, i);
        }
        for (ll j = 0; j < in[i]; ++j) {
            ll v;
            cin >> v;
            v--;
            E[v].emplace_back(i);
        }
    }
    ll res = 0, cnt = 0;
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        res = cur.first;
        cnt++;
        for (auto v : E[cur.second]) {
            in[v]--;
            if (in[v] == 0) {
                if (v > cur.second) {
                    q.emplace(cur.first, v);
                } else {
                    q.emplace(cur.first + 1, v);
                }
            }
        }
    }
    if (cnt < n) {
        cout << "-1\n";
    } else {
        cout << res << "\n";
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