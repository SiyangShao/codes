#include <bits/stdc++.h>
using namespace std;
auto solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> E(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    vector<int> col(n, -1);
    stack<int> st;
    function<bool(int, int)> dfs = [&](int x, int c) {
        col[x] = c;
        st.emplace(x);
        bool ans = true;
        for (auto v : E[x]) {
            if (col[v] != -1) {
                if (col[v] == col[x]) {
                    vector<int> ans;
                    while (!st.empty()) {
                        if (st.top() == v) {
                            ans.emplace_back(st.top());
                            break;
                        }
                        ans.emplace_back(st.top());
                        st.pop();
                    }
                    cout << ans.size() << "\n";
                    for (auto i : ans) {
                        cout << i + 1 << " ";
                    }
                    return false;
                }
            } else {
                ans = ans && dfs(v, 1 ^ c);
            }
            if (!ans) {
                return ans;
            }
        }
        st.pop();
        return ans;
    };
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            if (dfs(i, 0))
                continue;
            return;
        }
    }
    cout << "0\n";
    for (auto i : col) {
        cout << i << " ";
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