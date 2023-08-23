#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, z;
    cin >> n >> z;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    ll ans = *max_element(a.begin(), a.end());
    for (auto i : a) {
        ans = max(ans, i | z);
    }
    cout << ans << "\n";
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