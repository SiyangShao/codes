#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    vector<vector<int>> E(n);
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        E[a[i]].emplace_back(i);
    }
    for (auto &i : c) {
        cin >> i;
    }
    vector<int> not_choose(n), choose_odd(n), choose_even(n);
    // should odd
    // 1. choose_even, and connected with fa
    // 2. choose_odd, not connected with fa
    // 3. not choose
    function<void(int)> dfs = [&](int u) {
        not_choose[u] = 0;
        for (auto v : E[u]) {
            dfs(v);
            not_choose[u] += max(choose_odd[v], not_choose[v]);
        }
        // choose even, connected with fa
        choose_even[u] = c[u];
        priority_queue<int> eve;
        for (auto v : E[u]) {
            choose_even[u] += not_choose[v];
            eve.emplace(choose_even[v] - not_choose[v]);
        }
        while (eve.size() >= 2) {
            auto t1 = eve.top();
            eve.pop();
            auto t2 = eve.top();
            eve.pop();
            if (t1 + t2 >= 0) {
                choose_even[u] += t1 + t2;
            } else {
                break;
            }
        }
        // choose odd, not connected with fa
        if (E[u].empty()) {
            // is leaf
            not_choose[u] = choose_odd[u] = 0;
            choose_even[u] = c[u];
        } else {
            priority_queue<int> odd;
            choose_odd[u] = c[u];
            for (auto v : E[u]) {
                choose_odd[u] += not_choose[v];
                odd.emplace(choose_even[v] - not_choose[v]);
            }
            assert(!odd.empty());
            choose_odd[u] += odd.top();
            odd.pop();
            while (odd.size() >= 2) {
                auto t1 = odd.top();
                odd.pop();
                auto t2 = odd.top();
                odd.pop();
                if (t1 + t2 >= 0) {
                    choose_odd[u] += t1 + t2;
                } else {
                    break;
                }
            }
        }
    };
    dfs(0);
    cout << max(not_choose[0], choose_odd[0]) << "\n";
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