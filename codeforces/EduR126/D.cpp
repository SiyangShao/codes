#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct FenWickTree {
    vector<ll> tree;
    FenWickTree(int n) { tree.resize(n + 1); }
    void add(int i, ll x) {
        while (i < tree.size()) {
            tree[i] += x;
            i += i & -i;
        }
    }
    ll sum(int i) {
        ll res = 0;
        while (i > 0) {
            res += tree[i];
            i -= i & -i;
        }
        return res;
    }
};
auto solve() {
    ll n, k;
    cin >> n >> k;
    FenWickTree fw(k);
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (ll i = n - 1; i >= k - 1; --i) {
        auto l = max(0ll, k - (n - 1 - i));
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