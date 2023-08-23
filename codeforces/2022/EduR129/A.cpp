#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n;
    vector<ll> a(n);
    ll ma = 0, mb = 0;
    for (auto &i : a) {
        cin >> i;
        ma = max(ma, i);
    }
    cin >> m;
    vector<ll> b(m);
    for (auto &i : b) {
        cin >> i;
        mb = max(mb, i);
    }
    if (ma > mb) {
        cout << "Alice\nAlice\n";
    } else if (ma < mb) {
        cout << "Bob\nBob\n";
    } else {
        cout << "Alice\nBob\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}