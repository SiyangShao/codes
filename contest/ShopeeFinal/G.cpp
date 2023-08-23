#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, tmp;
vector<ll> initial;
vector<vector<ll>> E;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    E.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            if (i == j)
                continue;
            if (tmp == 1) {
                E[i].emplace_back(j);
            }
        }
    }
    while (cin >> tmp) {
        initial.emplace_back(tmp);
    }
    ll m = initial.size();
    sort(initial.begin(), initial.end());
    ll ans = initial[0], del = m - 1;
    for (int i = 0; i < m; ++i) {
        queue<ll> Node;
        vector<ll> vis;
        vis.assign(n, 0);
        vis[initial[i]] = 1;
        for (int j = 0; j < m; ++j) {
            vis[initial[j]] = 1;
            if (j == i)
                continue;
            Node.push(initial[j]);
        }
        ll cnt = 0;
        while (!Node.empty()) {
            auto top = Node.front();
            cnt++;
            Node.pop();
            for (auto &x : E[top]) {
                if (vis[x] == 0) {
                    vis[x] = 1;
                    Node.push(x);
                }
            }
        }
        if (cnt < del) {
            del = cnt;
            ans = initial[i];
        }
    }
    cout << ans;
}