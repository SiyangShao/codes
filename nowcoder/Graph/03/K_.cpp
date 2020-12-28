#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
const int maxm = 2e6 + 10;

int n, m;
int dislike[maxn][maxn];

vector<int> g[maxn];

int dfn[maxn], low[maxn], ts;
stack<int> stk;
vector<int> dcc[maxn];
int dcc_cnt;
bool cut[maxn];

int root;
void tarjan(int u) {
    dfn[u] = low[u] = ++ts;
    stk.push(u);

    if (u == root && g[u].empty()) {
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }

    int f = 0;
    for (auto v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                f++;
                if (u != root || f > 1)
                    cut[u] = true;
                ++dcc_cnt;
                int y;
                do {
                    y = stk.top();
                    stk.pop();
                    dcc[dcc_cnt].push_back(y);
                } while (y != v);
                dcc[dcc_cnt].push_back(u);
            }
        } else
            low[u] = min(low[u], dfn[v]);
    }
}

int col[maxn];
bool sv[maxn];
set<int> st;

bool dfs(int u, int c) {
    if (col[u])
        return col[u] == c;
    col[u] = c;
    for (auto v : g[u]) {
        if (!st.count(v))
            continue;
        if (!dfs(v, 3 - c))
            return false;
    }
    return true;
}

void check(int k) {
    vector<int> &v = dcc[k];
    st.clear();
    for (auto x : v)
     cout<<x<<" ",   st.insert(x);
    cout<<"\n";
    if (v.size() > 2 && !dfs(v[0], 1)) {
        for (auto x : v)
            sv[x] = 1;
    }

    for (auto x : v)
        col[x] = 0;
}

void init() {
    memset(dislike, 0, sizeof dislike);
    for (int i = 0; i < maxn; i++)
        g[i].clear();
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    ts = 0;
    while (stk.size())
        stk.pop();
    for (int i = 0; i < maxn; i++)
        dcc[i].clear();
    dcc_cnt = 0;
    memset(cut, 0, sizeof cut);
    memset(col, 0, sizeof col);
    memset(sv, 0, sizeof sv);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m && n && m) {

        init();

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            dislike[a][b] = dislike[b][a] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (dislike[i][j])
                    continue;
                g[i].push_back(j), g[j].push_back(i);
                // cout << i << " " << j << endl;
            }
        }

        for (root = 1; root <= n; root++)
            if (!dfn[root])
                tarjan(root);

        // for(int i = 1; i<=dcc_cnt; i++) {
        //     for(auto x : dcc[i]) cout << x << " ";
        //     cout << endl;
        // }

        for (int i = 1; i <= dcc_cnt; i++)
            check(i);

        // for(int i = 1; i<=n ; i++) cout << col[i] << " ";
        // cout << endl;

        cout << n - accumulate(sv + 1, sv + 1 + n, 0) << "\n";
    }

    return 0;
}