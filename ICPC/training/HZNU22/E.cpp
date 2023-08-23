#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll vis[55][55][55][55];
auto solve() {
    ll n;
    cin >> n;
    vector<string> mp(n);
    vector<ll> pos(4);
    memset(vis, -1, sizeof(vis));
    array<ll, 4> dx = {0, 1, 0, -1};
    array<ll, 4> dy = {1, 0, -1, 0};
    for (ll i = 0; i < n; ++i) {
        cin >> mp[i];
        for (ll j = 0; j < n; ++j) {
            if (mp[i][j] == 'a') {
                pos[0] = i, pos[1] = j;
                mp[i][j] = '.';
            } else if (mp[i][j] == 'b') {
                pos[2] = i, pos[3] = j;
                mp[i][j] = '.';
            }
        }
    }
    vis[pos[0]][pos[1]][pos[2]][pos[3]] = 0;
    queue<vector<ll>> Q;
    Q.push(pos);
    while (!Q.empty()) {
        auto cur = Q.front();
        if (cur[0] == cur[2] && cur[1] == cur[3]) {
            cout << vis[cur[0]][cur[1]][cur[2]][cur[3]] << "\n";
            return;
        }
        Q.pop();
        for (ll i = 0; i < 4; ++i) {
            auto nxt = cur;
            nxt[0] += dx[i], nxt[1] += dy[i], nxt[2] += dx[i], nxt[3] += dy[i];
            for (auto &j : nxt) {
                j = min(j, n - 1);
                j = max(j, 0LL);
            }
            if (mp[nxt[0]][nxt[1]] == '*') {
                nxt[0] -= dx[i], nxt[1] -= dy[i];
            }
            if (mp[nxt[2]][nxt[3]] == '*') {
                nxt[2] -= dx[i], nxt[3] -= dy[i];
            }
            if (vis[nxt[0]][nxt[1]][nxt[2]][nxt[3]] != -1) {
                continue;
            }
            if (nxt[0] == nxt[2] && nxt[1] == nxt[3]) {
                cout << vis[cur[0]][cur[1]][cur[2]][cur[3]] + 1 << "\n";
                return;
            }
            vis[nxt[0]][nxt[1]][nxt[2]][nxt[3]] =
                vis[cur[0]][cur[1]][cur[2]][cur[3]] + 1;
            Q.push(nxt);
        }
    }
    cout << "no solution\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}