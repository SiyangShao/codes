#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;
    if (n == 1) {
        if (a[0] == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    sort(a.begin(), a.end(), greater<>());
    if (a[0] - a[1] <= 1) {
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