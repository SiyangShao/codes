#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, d;
    cin >> n >> d;
    ll u, v;
    cin >> u >> v;
    vector<string> s(n);
    for (auto &i : s) {
        cin >> i;
    }
    vector<string> t(n);
    for (auto &i : t) {
        cin >> i;
    }
    array<ll, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
    auto neighbour = [&](int u, int v, const auto &cur) {
        int cnt = 0;
        if (u - 1 >= 0 && v - 1 >= 0) {
            cnt += cur[u - 1][v - 1] == '1';
        }
        if (u - 1 >= 0) {
            cnt += cur[u - 1][v] == '1';
        }
        if (u - 1 >= 0 && v + 1 < n) {
            cnt += cur[u - 1][v + 1] == '1';
        }
        if (v - 1 >= 0) {
            cnt += cur[u][v - 1] == '1';
        }
        if (v + 1 < n) {
            cnt += cur[u][v + 1] == '1';
        }
        if (u + 1 < n && v - 1 >= 0) {
            cnt += cur[u + 1][v - 1] == '1';
        }
        if (u + 1 < n) {
            cnt += cur[u + 1][v] == '1';
        }
        if (u + 1 < n && v + 1 < n) {
            cnt += cur[u + 1][v + 1] == '1';
        }
        return cnt;
    };
    auto update = [&](int u, int v, const auto &cur) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == u && j == v) {
                    s[i][j] = '0';
                } else {
                    if (cur[i][j] == '1') {
                        auto nei = neighbour(i, j, cur);
                        if (nei == 2 || nei == 3) {
                            s[i][j] = '1';
                        } else {
                            s[i][j] = '0';
                        }
                    } else {
                        if (neighbour(i, j, cur) == 3) {
                            s[i][j] = '1';
                        } else {
                            s[i][j] = '0';
                        }
                    }
                }
            }
        }
    };
     // update(u,v,cur);
    // for(int i = 0 ; i < n; ++i){
    //     cout<<s[i]<<"\n";
    // }
    function<bool(int, int, int)> dfs = [&](int u, int v, int d_rest) {
        if (d_rest == 0) {
            return s == t;
        }
        if (s == t) {
            return true;
        }
        const auto cur = s;
        bool ans = false;
        for (int i = 0; i < 4; ++i) {
            auto nu = u + dx[i], nv = v + dy[i];
            if (nu < 0 || nu >= n || nv < 0 || nv >= n) {
                continue;
            }
            s = cur;
            update(nu, nv, cur);
            ans = ans || dfs(nu, nv, d_rest - 1);
        }
        return ans;
    };
    if (dfs(u, v, d)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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