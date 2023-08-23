#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    vector<pair<ll, ll>> ans;
    ans.clear();
    for (ll i = 0; i < n - 1; ++i) {
        for (ll j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1] || b[j] > b[j + 1]) {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                ans.emplace_back(j, j + 1);
            }
        }
    }
    if (is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end())) {
        cout << ans.size() << "\n";
        for (auto &[l, r] : ans) {
            cout << l + 1 << " " << r + 1 << "\n";
        }
    } else {
        cout << "-1\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}