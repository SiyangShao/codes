#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    vector<int> x, y;
    ll cnt = 1;
    for (auto &[f, s] : a) {
        cin >> f >> s;
        if (f > s) {
            x.emplace_back(cnt);
        } else {
            y.emplace_back(cnt);
        }
        cnt++;
    }
    if (x.size() < y.size()) {
        x = move(y);
        sort(x.begin(), x.end(),
             [&a](auto l, auto r) { return a[l - 1].first > a[r - 1].first; });
    } else {
        sort(x.begin(), x.end(), [&a](auto l, auto r) {
            return a[l - 1].second < a[r - 1].second;
        });
    }
    cout << x.size() << "\n";
    for (auto i : x) {
        cout << i << " ";
    }
    cout << "\n";
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