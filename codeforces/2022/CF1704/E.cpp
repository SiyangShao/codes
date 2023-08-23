#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
auto solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), in(n, 0), b(n, 0);
    for (auto &i : a) {
        cin >> i;
    }
    vector<vector<ll>> E(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        in[v]++;
        E[u].emplace_back(v);
    }
    if (*max_element(a.begin(), a.end()) == 0) {
        cout << "0\n";
        return;
    }
    function<bool()> topo = [&]() {
        auto deg = in;
        queue<int> Q;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                Q.emplace(i);
            }
        }
        while (!Q.empty()) {
            auto u = Q.front();
            Q.pop();
            bool flag = a[u] > 0;
            if (flag) {
                a[u]--;
            }
            a[u] += b[u];
            b[u] = 0;
            for (auto v : E[u]) {
                deg[v]--;
                if (!deg[v]) {
                    Q.emplace(v);
                }
                if (flag) {
                    b[v]++;
                }
            }
        }
        return *max_element(a.begin(), a.end()) == 0;
    };
    for (int i = 1; i <= n; ++i) {
        if (topo()) {
            cout << i << "\n";
            return;
        }
        // for(int j = 0 ; j < n; ++j){
        //     cout<<a[j]<<" ";
        // }
        // cout<<"\n";
    }
    function<ll()> dp = [&]() {
        auto deg = in;
        queue<int> Q;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                Q.emplace(i);
            }
        }
        while (!Q.empty()) {
            auto u = Q.front();
            if (E[u].empty()) {
                ans = a[u];
            }
            Q.pop();
            for (auto v : E[u]) {
                a[v] = (a[v] + a[u]) % MOD;
                deg[v]--;
                if (!deg[v]) {
                    Q.emplace(v);
                }
            }
        }
        return ans;
    };
    cout << (dp() + n) % MOD << "\n";
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