#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y)
            return x;
        if (-parent_or_size[x] < -parent_or_size[y])
            std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0)
            return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(
                         result.begin(), result.end(),
                         [&](const std::vector<int> &v) { return v.empty(); }),
                     result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

} // namespace atcoder
using namespace atcoder;
ll n;
constexpr ll MOD = 998244353;
vector<pair<ll, ll>> point;
array<array<ll, 110>, 110> mp, dp, C, A;
vector<vector<ll>> nxt;
vector<ll> vis;
auto judge(vector<ll> &tmp, ll len) {
    for (auto i : tmp) {
        // cout << i << " " << nxt[i][tmp.size()] << " "
        //      << mp[i][nxt[i][tmp.size()]] << " " << len << "\n";
        if (tmp.size() < n && mp[i][nxt[i][tmp.size()]] <= len) {
            return false;
        }
    }
    for (ll i = 0; i < tmp.size(); ++i) {
        for (ll j = i + 1; j < tmp.size(); ++j) {
            if (mp[tmp[i]][tmp[j]] != len) {
                return false;
            }
        }
    }
    return true;
}
auto init() {
    C[0][0] = 1;
    for (ll i = 1; i <= 100; ++i) {
        for (ll j = 0; j <= i; ++j) {
            if (j == 0) {
                C[i][j] = 1;
            } else if (i == j) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                C[i][j] %= MOD;
            }
        }
        if (i == 1) {
            A[i][i] = 1;
        } else {
            A[i][i] = (A[i - 1][i - 1] * i) % MOD;
        }
    }
}
auto solve() {
    cin >> n;
    point.resize(n);
    nxt.resize(n);
    vis.assign(n, 0);
    dsu DSU(n);
    for (auto &[x, y] : point) {
        cin >> x >> y;
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            mp[i][j] = abs(point[i].first - point[j].first) +
                       abs(point[i].second - point[j].second);
        }
        nxt[i].resize(n);
        iota(nxt[i].begin(), nxt[i].end(), 0);
        sort(nxt[i].begin(), nxt[i].end(),
             [&](auto l, auto r) { return mp[i][l] < mp[i][r]; });
        // for (ll j = 0; j < n; ++j) {
        //     cout << nxt[i][j] << " ";
        // }
        // cout << "\n";
    }
    for (ll i = 0; i < n; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            vector<ll> tmp = {i, nxt[i][1]};
            for (ll j = 2; j < n; ++j) {
                if (mp[i][nxt[i][1]] == mp[i][nxt[i][j]]) {
                    tmp.emplace_back(nxt[i][j]);
                } else {
                    break;
                }
            }
            if (judge(tmp, mp[i][nxt[i][1]])) {
                for (ll j = 1; j < tmp.size(); ++j) {
                    DSU.merge(tmp[0], tmp[j]);
                }
                for (auto j : tmp) {
                    // cout << j << " ";
                    vis[j] = 1;
                }
                // cout << "YES\n";
                // cout << "\n";
            } else {
                // cout << "NO\n";
            }
        }
    }
    auto grp = DSU.groups();
    vector<ll> size(grp.size() + 1);
    for (ll i = 1; i <= grp.size(); ++i) {
        size[i] = grp[i - 1].size();
        // cout << size[i] << " ";
        // for (auto j : grp[i - 1]) {
        //     cout << j << " ";
        // }
        // cout << "\n";
    }
    size[0] = 0;
    ll m = size.size() - 1;
    ll pre = 0;
    dp[0][0] = 1;
    for (ll i = 1; i <= m; ++i) {
        for (ll j = 0; j <= pre; ++j) {
            if (size[i] != 1)
                dp[i][j + size[i]] = (dp[i][j + size[i]] + dp[i - 1][j]) % MOD;
            dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
        }
        pre += size[i];
    }
    ll ans = 0;
    for (ll i = m; i <= n; ++i) {
        ans = (ans + (dp[m][i] * ((A[i][i] * C[n][i]) % MOD)) % MOD) % MOD;
        // cout << i << " " << dp[m][i] << " " << A[i][i] << " " << C[n][i]
        //      << "\n";
    }
    cout << ans << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    init();
    // cin >> _;
    while (_--) {
        solve();
    }
}