#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * @brief
 * Observation: The question is to ask minimum time using skybridges.
 * Edge case: when x==y, answer should be 0 or 1
 * Then always consider condition when x < y
 * Merge intersecting segments in same elevator
 */
constexpr ll N = 2e6 + 7, INF = 1e9 + 7;
ll n, m, Q;
vector<ll> b;
array<ll, N> nxt, dep;
array<array<ll, 21>, N> dp;
map<ll, ll> id;
array<vector<pair<ll, ll>>, N> p;
array<array<ll, 4>, N> que;
auto update(vector<pair<ll, ll>> &v) {
    sort(v.begin(), v.end());
    vector<pair<ll, ll>> tmp;
    tmp.clear();
    ll L = -1, R = 0;
    for (auto [l, r] : v) {
        if (L == -1) {
            L = l, R = r;
        } else {
            if (l > R) {
                tmp.emplace_back(L, R);
                L = l;
            }
            R = max(R, r);
        }
    }
    if (L != -1) {
        tmp.emplace_back(L, R);
    }
    v = tmp;
}
pair<ll, ll> get(ll x, ll y) {
    auto pos = upper_bound(p[x].begin(), p[x].end(), make_pair(y, INF)) -
               p[x].begin() - 1LL;
    if (pos != -1)
        if (y >= p[x][pos].first && y <= p[x][pos].second)
            return {id[p[x][pos].first], id[p[x][pos].second]};
    return {-1LL, -1LL};
}

auto solve() {
    cin >> n >> m >> Q;
    for (ll i = 1; i <= m; ++i) {
        ll a, l, r;
        cin >> a >> l >> r;
        p[a].emplace_back(l, r);
    }
    for (ll i = 1; i <= Q; ++i) {
        cin >> que[i][0] >> que[i][1] >> que[i][2] >> que[i][3];
        p[que[i][0]].emplace_back(que[i][1], que[i][1]);
        p[que[i][2]].emplace_back(que[i][3], que[i][3]);
    }
    for (ll i = 1; i <= n; ++i) {
        update(p[i]);
        for (auto [l, r] : p[i]) {
            b.emplace_back(l);
            b.emplace_back(r);
        }
    }
    b.emplace_back(-INF);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (ll i = 1; i < b.size(); ++i) {
        id[b[i]] = i;
    }
    for (ll i = 1; i <= n; ++i) {
        for (auto [l, r] : p[i]) {
            ll L = lower_bound(b.begin(), b.end(), l) - b.begin();
            ll R = lower_bound(b.begin(), b.end(), r) - b.begin();
            nxt[L] = max(nxt[L], R);
        }
    }
    for (ll i = 1; i < b.size(); ++i) {
        nxt[i] = max(nxt[i - 1], nxt[i]);
    }
    for (ll i = b.size() - 1; i >= 1; --i) {
        if (nxt[i] <= i) {
            dp[i][0] = b.size();
        } else {
            dp[i][0] = nxt[i];
        }
        dep[i] = dep[dp[i][0]] + 1;
    }
    dp[b.size()][0] = b.size();
    for (ll j = 1; j <= 20; ++j) {
        for (ll i = 1; i <= b.size(); ++i) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    for (ll i = 1; i <= Q; ++i) {
        auto [x, y, z, w] = que[i];
        if (y > w) {
            swap(x, z);
            swap(y, w);
        }
        auto ans = w - y;
        if (y == w) {
            if (x == z) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
            continue;
        }
        auto r = get(x, y).second;
        auto l = get(z, w).first;
        if (l == -1 || r == -1) {
            cout << "-1\n";
            continue;
        }
        if (r >= l) {
            cout << ans + (x != z) << "\n";
            continue;
        }
        auto tmp = r;
        for (ll i = 20; i >= 0; --i) {
            if (dp[tmp][i] < l) {
                tmp = dp[tmp][i];
            }
        }
        tmp = dp[tmp][0];
        if (tmp == b.size()) {
            cout << "-1\n";
            continue;
        }
        ans += dep[r] - dep[tmp] + 1;
        cout << ans << "\n";
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