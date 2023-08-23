#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> E(n * 2);
    vector<pair<ll, ll>> p(n);
    for (auto &[l, r] : p) {
        cin >> l >> r;
        l--, r--;
        E[l].emplace_back(r);
        E[r].emplace_back(l);
    }
    for (ll i = 0; i < n; ++i) {
        E[i * 2].emplace_back(i * 2 + 1);
        E[i * 2 + 1].emplace_back(i * 2);
    }
    vector<ll> col(n * 2, 0);
    queue<ll> Q;
    function<bool(ll)> bfs = [&](ll s) {
        Q.emplace(s);
        col[s] = 1;
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for (auto v : E[cur]) {
                if (col[v] == 0) {
                    col[v] = col[cur] == 1 ? 2 : 1;
                    Q.emplace(v);
                } else if (col[v] == col[cur]) {
                    return false;
                }
            }
        }
        return true;
    };
    for (ll i = 0; i < n * 2; ++i) {
        if (col[i] == 0) {
            if (!bfs(i)) {
                cout << "-1\n";
                return;
            }
        }
    }
    for (auto [l, r] : p) {
        cout << col[l] << " " << col[r] << "\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}