#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 50;
array<array<ll, N>, N> mp;
array<ll, N> at, home, bed, vis;
auto solve() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> at[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> home[i];
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] == 1 && at[j] == 1) {
                mp[i][j] = 1;
            } else {
                mp[i][j] = 0;
            }
            if (i == j && at[j] == 1 && home[j] == 0) {
                mp[i][j] = 1;
            }
            // i can sleep on bed j
        }
    }
    function<bool(ll)> dfs = [&](ll u) {
        for (ll j = 0; j < n; ++j) {
            if (mp[u][j] == 0 || vis[j])
                continue;
            if (bed[j] == -1) {
                bed[j] = u;
                return true;
            } else {
                vis[j] = 1;
                if (dfs(bed[j])) {
                    bed[j] = u;
                    return true;
                } else {
                    // vis[j] = 0;
                }
            }
        }
        return false;
    };
    bed.fill(-1);
    for (ll i = 0; i < n; ++i) {
        if (at[i] == 0 || home[i] == 0) {
            vis.fill(0);
            if (!dfs(i)) {
                cout << "T_T\n";
                return;
            }
        }
    }
    cout << "^_^\n";
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