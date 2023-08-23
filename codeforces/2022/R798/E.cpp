#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class DSU {
  public:
    vector<ll> fa, siz;
    ll n;
    DSU(ll _n) : n(_n) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        siz.assign(n, 1);
    }
    auto find(ll u) {
        if (u == fa[u])
            return fa[u];
        return fa[u] = find(fa[u]);
    }
    auto merge(ll u, ll v) {
        u = find(u), v = find(v);
        if (u == v)
            return false;
        if (siz[u] > siz[v])
            swap(u, v);
        fa[u] = v;
        siz[v] += siz[u];
        return true;
    }
};
constexpr ll bit = 30;
auto judge(const vector<ll> &a) {
    const ll siz = a.size();
    DSU dsu(siz + bit);
    for (ll i = 0; i < siz; ++i) {
        for (ll j = 0; j < bit; ++j) {
            if ((a[i] >> j) & 1) {
                dsu.merge(i, siz + j);
            }
        }
    }
    for (ll i = 1; i < siz; ++i) {
        if (dsu.find(0) != dsu.find(i))
            return false;
    }
    return true;
}
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    for (auto &i : a) {
        cin >> i;
        if (!i) {
            i++;
            ans++;
        }
    }
    auto output = [&](auto num) {
        cout << num << "\n";
        for (auto i : a) {
            cout << i << " ";
        }
        cout << "\n";
    };
    if (judge(a)) {
        output(ans);
        return;
    }
    for (ll i = 0; i < n; ++i) {
        a[i]--;
        if (judge(a)) {
            output(ans + 1);
            return;
        }
        a[i] += 2;
        if (judge(a)) {
            output(ans + 1);
            return;
        }
        a[i]--;
    }
    ll h = 0;
    for (auto i : a) {
        h = max(h, i & -i);
    }
    ll num = 0;
    for (ll i = 0; i < n; ++i) {
        if ((a[i] & -a[i]) == h) {
            if (num == 0) {
                a[i]--;
                num++;
            } else {
                a[i]++;
                output(ans + 2);
                return;
            }
        }
    }
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