#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1002;
bool mp[N][N], vis[N][N];
vector<pair<int, int>> E[N * N];
int n, m, d;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int cnt = 0) {
    vis[x][y] = true;
//    cout << x << " " << y << "\n";
    if (cnt != 0)E[cnt].push_back({x, y});
    for (int i = 0; i < 4; ++i) {
        auto nx = x + dx[i], ny = y + dy[i];
        if (nx > n || ny > m || nx < 1 || ny < 1) continue;
        if (!vis[nx][ny])
            dfs(nx, ny, cnt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> d;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            if (s[j - 1] == '#') {
                mp[i][j] = true;
            } else {
                mp[i][j] = false;
            }
            vis[i][j] = mp[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (vis[i][j]) continue;
            if (i == 1 || j == 1 || i == n || j == m) {
                dfs(i, j, 0);
            } else {
                cnt++;
                dfs(i, j, cnt);
            }
        }
    }
    sort(E + 1, E + 1 + cnt, [](auto x, auto y) {
        return x.size() < y.size();
    });
    for (int i = 1; i <= cnt; ++i) {
        if (d > E[i].size()) {
            for (auto[x, y]: E[i]) {
                mp[x][y] = true;
            }
        } else {
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << (mp[i][j] ? '#' : '.');
        }
        cout << "\n";
    }
}