#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array dx = {0, -1, 0, 1, 0}, dy = {1, 0, -1, 0, 0};
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector a(n, vector<ll>(m));
    for (auto &i : a) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    /**
     * @brief
     * Observation: it is solvable if and only if each node has an adjacent node
     * smaller. (except 1)
     */
    set<pair<ll, ll>> st;
    auto adj = [&](auto x, auto y) {
        assert(x >= 0 && x < n && y >= 0 && y < m);
        st.clear();
        for (ll k = 0; k < 5; ++k) {
            ll nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            st.emplace(nx, ny);
        }
    };
    auto check = [&](auto x, auto y) {
        if (a[x][y] == 1)
            return true;
        for (ll k = 0; k < 4; ++k) {
            ll nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (a[nx][ny] < a[x][y])
                return true;
        }
        return false;
    };
    set<pair<ll, ll>> bad;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (!check(i, j)) {
                bad.emplace(i, j);
            }
        }
    }
    if (bad.empty()) {
        cout << "0\n";
        return;
    }
    /**
     * @brief
     * Observation: If we want after a swap to become solvable, the swap SHOULD
     * be on the bad node or it's adjancent node
     */
    if (bad.size() < 5) {
        set<pair<pair<ll, ll>, pair<ll, ll>>> ans;
        for (auto [x0, y0] : bad) {
            adj(x0, y0);
            auto tmp = st;
            for (auto [x, y] : tmp) {
                for (ll i = 0; i < n; ++i) {
                    for (ll j = 0; j < m; ++j) {
                        bool flag = true;
                        for (auto &[u, v] : bad) {
                            if (abs(u - x) + abs(v - y) > 1 &&
                                abs(u - i) + abs(v - j) > 1) {
                                flag = false;
                            }
                        }
                        if (flag) {
                            swap(a[i][j], a[x][y]);
                            for (auto [nx, ny] : array<pair<ll, ll>, 2>{
                                     pair<ll, ll>{i, j}, {x, y}}) {
                                adj(nx, ny);
                                auto ttmp = st;
                                for (auto [jx, jy] : ttmp) {
                                    if (!check(jx, jy)) {
                                        flag = false;
                                        break;
                                    }
                                }
                                if (!flag)
                                    break;
                            }
                            swap(a[i][j], a[x][y]);
                        }
                        if (flag) {
                            pair<ll, ll> L = {i, j}, R = {x, y};
                            if (L < R) {
                                swap(L, R);
                            }
                            ans.emplace(L, R);
                        }
                    }
                }
            }
            /**
             * @brief
             * Observation: The swap one MUST be the neighbour of EVERY bad node
             */
            break;
        }
        if (!ans.empty()) {
            cout << "1 " << ans.size() << "\n";
            return;
        }
    }
    cout << "2\n";
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