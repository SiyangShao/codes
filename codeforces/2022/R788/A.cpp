#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll cnt = 0;
    for (auto &i : a) {
        cin >> i;
        if (i < 0)
            cnt++;
        i = abs(i);
    }
    for (int i = 0; i < cnt; ++i) {
        a[i] = -a[i];
    }
    if (is_sorted(a.begin(), a.end())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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