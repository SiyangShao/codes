#include <array>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e5 + 7;
array<set<ll>, N> st;
bitset<N> vis, inq, dvis;
vector<ll> per, ans;
array<vector<ll>, N> E;
map<pair<ll, ll>, ll> mp;
auto dfs(ll u, ll fa) {
    if (dvis[u])
        return;
    dvis[u] = true;
    per.emplace_back(u);
    for (auto v : E[u]) {
        if (v != fa) {
            dfs(v, u);
        }
    }
}
auto init(ll n) {
    for (ll i = 0; i <= n; ++i) {
        st[i].clear();
        vis[i] = false, inq[i] = false, dvis[i] = false;
        E[i].clear();
    }
    mp.clear();
    per.clear(), ans.clear();
}
auto solve() {
    ll n;
    cin >> n;
    init(n);
    ll ttt = 0;
    vector<array<ll, 3>> all(n - 2);
    for (auto &i : all) {
        cin >> i[0] >> i[1] >> i[2];
        i[0]--, i[1]--, i[2]--;
    }
    for (auto &i : all) {
        sort(i.begin(), i.end());
        mp[{i[0], i[1]}]++;
        mp[{i[1], i[2]}]++;
        mp[{i[0], i[2]}]++;
        ttt++;
        st[i[0]].insert(ttt);
        st[i[1]].insert(ttt);
        st[i[2]].insert(ttt);
    }
    for (auto [_, cnt] : mp) {
        if (cnt == 1) {
            E[_.first].emplace_back(_.second);
            E[_.second].emplace_back(_.first);
        }
    }
    queue<ll> q1, q2;
    for (int i = 1; i <= n - 2; i++) {
        auto [a, b, c] = all[i - 1];
        if (st[a].size() == 1 || st[b].size() == 1 || st[c].size() == 1)
            q2.push(i);
    }
    q1.push(q2.front());
    q2.pop();
    while (!q1.empty()) {
        auto u = q1.front();
        q1.pop();
        auto [a, b, c] = all[u - 1];
        st[a].erase(u);
        st[b].erase(u);
        st[c].erase(u);
        ans.push_back(u);
        if (st[a].size() == 1) {
            if (!inq[*st[a].begin()])
                q1.push(*st[a].begin());
            inq[*st[a].begin()] = true;
        }
        if (st[b].size() == 1) {
            if (!inq[*st[b].begin()])
                q1.push(*st[b].begin());
            inq[*st[b].begin()] = true;
        }
        if (st[c].size() == 1) {
            if (!inq[*st[c].begin()])
                q1.push(*st[c].begin());
            inq[*st[c].begin()] = true;
        }
        if (q1.empty()) {
            while (!q2.empty() && inq[q2.front()])
                q2.pop();
            if (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
    dfs(0, -1);
    for (auto u : per)
        cout << u + 1 << " ";
    cout << "\n";
    for (auto u : ans)
        cout << u << " ";
    cout << "\n";
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