#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(k);
    ll mx = 0;
    for (auto &i : a) {
        cin >> i;
        mx = max(mx, i);
    }
    bool flag = false;
    for (auto &i : b) {
        cin >> i;
        i--;
        if (a[i] == mx) {
            flag = true;
        }
    }
    if (flag) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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