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
    ll cnt = 0;
    reverse(a.begin(), a.end());
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == 0) {
            cout << "-1\n";
            return;
        }
        while (a[i] >= a[i - 1]) {
            a[i] /= 2;
            cnt++;
        }
    }
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