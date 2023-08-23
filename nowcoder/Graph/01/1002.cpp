// https://ac.nowcoder.com/acm/contest/26077/1002
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> E(n);
    vector mp(vector<vector<ll>>(n, vector<ll>(n, 0)));
    vector<ll> out(n, 0);
    for (ll i = 0; i < m; ++i) {
        ll s;
        cin >> s;
        vector<ll> tmp(s);
        unordered_set<ll> st;
        st.clear();
        for (auto &j : tmp) {
            cin >> j;
            j--;
            st.insert(j);
        }
        ll L = tmp[0], R = tmp[s - 1];
        for (ll j = L + 1; j < R; ++j) {
            if (st.find(j) != st.end())
                continue;
            for (ll k = 0; k < s; ++k) {
                if (mp[j][tmp[k]] == 1)
                    continue;
                E[j].emplace_back(tmp[k]);
                out[tmp[k]]++;
                mp[j][tmp[k]] = 1;
            }
        }
    }
    vector<ll> dp(n, 0);
    queue<ll> Q;
    for (ll i = 0; i < n; ++i) {
        if (out[i] == 0) {
            Q.emplace(i);
            dp[i] = 1;
        }
    }
    while (!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        for (auto v : E[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            out[v]--;
            if (out[v] == 0) {
                Q.emplace(v);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
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