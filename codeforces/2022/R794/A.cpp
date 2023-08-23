#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &i : a) {
        cin >> i;
        sum += i;
    }
    if (sum % n != 0) {
        cout << "NO\n";
        return;
    }
    sum /= n;
    for (auto i : a) {
        if (i == sum) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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