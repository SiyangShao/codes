#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m, k;
    cin >> n >> m;
    vector<ll> a(n);
    vector<pair<ll, ll>> rev_a, rev_b;
    rev_a.clear();
    rev_b.clear();
    for (auto &i : a) {
        cin >> i;
    }
    for (auto i : a) {
        ll res = 1;
        while (i % m == 0) {
            res *= m;
            i /= m;
        }
        ll siz = rev_a.size();
        if (siz != 0 && rev_a[siz - 1].first == i) {
            rev_a[siz - 1].second += res;
        } else {
            rev_a.emplace_back(i, res);
        }
    }
    cin >> k;
    vector<ll> b(k);
    for (auto &i : b) {
        cin >> i;
    }
    for (auto i : b) {
        ll res = 1;
        while (i % m == 0) {
            res *= m;
            i /= m;
        }
        ll siz = rev_b.size();
        if (siz != 0 && rev_b[siz - 1].first == i) {
            rev_b[siz - 1].second += res;
        } else {
            rev_b.emplace_back(i, res);
        }
    }
    // for (auto i : rev_a) {
    //     cout << i.first << "," << i.second << " ";
    // }
    // cout << "\n";
    // for (auto i : rev_b) {
    //     cout << i.first << "," << i.second << " ";
    // }
    // cout << "\n";
    if (rev_a == rev_b) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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