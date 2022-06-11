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
    if (n == 1) {
        cout << "-1\n";
        return;
    }
    vector<ll> b(a);
    sort(b.begin(), b.end());
    for (ll i = 0; i + 1 < n; ++i) {
        if (b[i] == a[i]) {
            swap(b[i], b[i + 1]);
        }
    }
    if (a[n - 1] == b[n - 1]) {
        swap(b[n - 1], b[n - 2]);
    }
    for (auto i : b) {
        cout << i << " ";
    }
    cout << "\n";
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