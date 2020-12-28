#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 2e5 + 5;

inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

int n, m;
vector<int> col(maxn, -1);
vector<int> E[maxn], V[maxn];
vector<vector<int>> G;
vector<int> topo, vis(maxn), pos(maxn);

bool d(int u) {
    vis[u] = -1;
    for (auto v: V[u]) {
        if (vis[v] < 0) return false;
        else if (!vis[v]) {
            if (!d(v)) return false;
        }
    }
    vis[u] = 1;
    topo.emplace_back(u);
    return true;
}

bool toposort() {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            if (!d(i)) return false;
        }
    }
    reverse(topo.begin(), topo.end());
    return true;
}

bool dfs(int u, int fa) {
    for (auto v: E[u]) {
        if (v == fa) continue;
        if (col[v] == col[u]) {
            return false;
        } else if (col[v] == -1) {
            col[v] = col[u] ^ 1;
            if (!dfs(v, u)) return false;
        }
    }
    return true;
}

int main() {
    n = read(), m = read();
    G.resize(m, vector<int>(3, 0));
    for (auto &i: G) {
        for (auto &j: i) {
            j = read();
        }
        E[i[1]].emplace_back(i[2]);
        E[i[2]].emplace_back(i[1]);
    }
    for (int i = 1; i <= n; ++i) {
        if (col[i] == -1) {
            col[i] = 0;
            if (!dfs(i, 0)) {
                printf("NO");
                return 0;
            }
        }
    }
    for (auto i: G) {
        auto u = i[1], v = i[2];
        if (col[u] == 1) {
            swap(u, v);
        }
        if (i[0] == 1) {
            V[u].emplace_back(v);
        } else {
            V[v].emplace_back(u);
        }
    }
    if (toposort()) {
        auto cnt = 0;
        for (auto i: topo) {
            pos[i] = ++cnt;
        }
        printf("YES\n");
        for (int i = 1; i <= n; ++i) {
            if (col[i] == 0) {
                printf("L %d\n", pos[i]);
            } else {
                printf("R %d\n", pos[i]);
            }
        }
    } else {
        printf("NO");
    }
}