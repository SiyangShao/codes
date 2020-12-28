#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll odd = 0, even = 0;
    for (auto &i : a) {
        cin >> i;
        if (i % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    cout << min(odd, even) << "\n";
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