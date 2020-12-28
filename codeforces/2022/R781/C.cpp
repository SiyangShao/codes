#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
ll n;
vector<vector<ll>> E;
auto solve() {
    cin >> n;
    E.assign(n, vector<ll>());
    for (ll i = 1, v; i < n; ++i) {
        cin >> v;
        E[v - 1].emplace_back(i);
    }
    vector<ll> a(n);
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(),
         [&](ll x, ll y) { return E[x].size() > E[y].size(); });
    ll cnt = n;
    for (ll i = 0; i < n; ++i) {
        if (E[a[i]].size() == 0) {
            cnt = i;
            break;
        }
    }
    priority_queue<ll> Q;
    for (ll i = 0; i < cnt; ++i) {
        if (E[a[i]].size() > 1)
            Q.emplace(E[a[i]].size() - (cnt - i) - 1);
    }
    ll add = 0;
    while (!Q.empty() && Q.top() > add) {
        add++;
        auto t = Q.top();
        Q.pop();
        t--;
        Q.push(t);
    }
    cout << cnt + add + 1 << "\n";
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