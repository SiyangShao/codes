#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    auto b = a;
    sort(b.begin(), b.end(), greater<>());
    ll cur = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[0]) {
            cur = i;
            break;
        }
    }
    ll l = cur, r = cur;
    for (int i = 1; i < n; ++i) {
        if ((l - 1 >= 0 && a[l - 1] == b[i])) {
            l--;
        } else if ((r + 1 < n && a[r + 1] == b[i])) {
            r++;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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