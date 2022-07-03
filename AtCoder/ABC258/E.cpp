#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, q, x;
    cin >> n >> q >> x;
    vector<ll> w(n);
    ll sum_all = 0;
    for (auto &i : w) {
        cin >> i;
        sum_all += i;
    }
    ll __bs = x / sum_all;
    x -= __bs * sum_all;
    vector<ll> pre(n * 2 + 1, 0);
    for (ll i = 1; i <= n * 2; ++i) {
        pre[i] = pre[i - 1] + w[(i - 1) % n];
    }
    vector<ll> size(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        ll bs = pre[i - 1];
        ll need = bs + x;
        ll pos = lower_bound(pre.begin(), pre.end(), need) - pre.begin();
        size[i] = pos - (i - 1);
    }
    vector<ll> l, r;
    vector<ll> vis(n + 1, 0);
    ll cur = 1;
    while (!vis[cur]) {
        l.emplace_back(size[cur]);
        vis[cur] = 1;
        cur = cur + size[cur];
        if (cur > n) {
            cur -= n;
        }
    }
    vis.assign(n + 1, 0);
    while (!vis[cur]) {
        r.emplace_back(size[cur]);
        vis[cur] = 1;
        cur = cur + size[cur];
        if (cur > n) {
            cur -= n;
        }
    }
    ll L = l.size(), R = r.size();
    while (q--) {
        long long k;
        cin >> k;
        k--;
        if (k < L) {
            cout << l[k] + __bs * n << "\n";
        } else {
            k -= L;
            k %= R;
            cout << r[k] + __bs * n << "\n";
        }
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