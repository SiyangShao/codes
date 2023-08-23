#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    cout << n;
    for (int i = 1; i < n; ++i) {
        cout << " " << i;
    }
    cout << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    auto _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}