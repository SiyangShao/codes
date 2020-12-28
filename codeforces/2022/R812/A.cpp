#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    ll L = 0, R = 0, U = 0, D = 0;
    for (int i = 0; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        U = max(U, v);
        D = min(D, v);
        L = min(u, L);
        R = max(u, R);
    }
    ll cnt = abs(U) + abs(D) + abs(L) + abs(R);
    cnt *= 2;
    cout << cnt << "\n";
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