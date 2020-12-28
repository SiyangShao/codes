#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
        if (n % 2 == 1 && mp[i] > (n + 1) / 2) {
            cout << "NO\n";
            return;
        }
        if (n % 2 == 0 && mp[i] > n / 2) {
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
    // cin >> _;
    while (_--) {
        solve();
    }
}