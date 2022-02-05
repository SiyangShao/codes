#include <bits/stdc++.h>

#define int ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

inline int line(int x, int y, int u, int v) {
    if (x == u) {
        if (y > v) swap(y, v);
        return x * (k + 1) * (k + 1) * (k + 1) + y * (k + 1) * (k + 1) + u * (k + 1) + v;
    } else {
        if (x > u) swap(x, u);
        return x * (k + 1) * (k + 1) * (k + 1) + y * (k + 1) * (k + 1) + u * (k + 1) + v;
    }
}


void solve() {
    cin >> n >> k;
    unordered_map<int, int> mp;
    mp.clear();
    for (int i = 1, r1, r2, c1, c2; i <= n; ++i) {
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == r2) {
            if (c1 > c2) swap(c1, c2);
            mp[line(r1 - 1, c1, r1, c1)]++;
            mp[line(k - r1 + 1, k - c1, k - r1, k - c1)]++;
        } else {
            if (r1 > r2) swap(r1, r2);
            mp[line(r1, c1 - 1, r1, c1)]++;
            mp[line(k - r1, k - c1 + 1, k - r1, k - c1)]++;
        }
    }
    vector<vi> dis(k + 1, vi(k + 1, 0x3f3f3f3f3f3f3f3f));
    priority_queue<vi, vector<vi>, greater<>> q;
    vi first = {0, 0, 0};
    dis[0][0] = 0;
    q.push(first);
    while (!q.empty()) {
        auto now = q.top();
        q.pop();
        auto x = now[1], y = now[2];
        if (now[0] > dis[x][y]) continue;
        for (int i = 0; i < 4; ++i) {
            auto u = x + dx[i], v = y + dy[i];
            if (u > k || v > k || u < 0 || v < 0) continue;
            if (dis[u][v] > dis[x][y] + mp[line(x, y, u, v)]) {
                dis[u][v] = dis[x][y] + mp[line(x, y, u, v)];
                q.push({dis[u][v], u, v});
            }
        }
    }
//    cout << "\n";
//    for (int i = 0; i <= k; ++i) {
//        for (int j = 0; j <= k; ++j) {
//            cout << dis[i][j] << " ";
//        }
//        cout << "\n";
//    }
    cout << n - dis[k / 2][k / 2] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}