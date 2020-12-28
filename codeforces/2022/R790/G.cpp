#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 我走在每天必须面对的分岔路
// 我怀念过去单纯美好的小幸福
auto solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> E(n);
    vector<pair<ll, ll>> num(n);
    ll cnt = 0;
    num.assign(n, {0, 0});
    E.assign(n, vector<ll>());
    for (int i = 1; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        tmp--;
        E[tmp].emplace_back(i);
    }
    string s;
    cin >> s;
    auto dfs = [&](auto self, auto u) -> void {
        if (s[u] == 'W') {
            num[u].first++;
        } else {
            num[u].second++;
        }
        for (auto v : E[u]) {
            self(self, v);
            num[u].first += num[v].first;
            num[u].second += num[v].second;
        }
        if (num[u].first == num[u].second) {
            cnt++;
        }
    };
    dfs(dfs, 0);
    cout << cnt << "\n";
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