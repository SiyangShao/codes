#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> k >> n;
    // assert 1: no 2 has the same amount
    vector<ll> a(n);
    a[0] = 1;
    ll sum = 1;
    for (int i = 1; i < n; ++i) {
        a[i] = a[i - 1] * 2;
        sum += a[i];
        if (sum > k) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    a[n - 1] += k - sum;
    for (auto &i : a) {
        cout << i << " ";
    }
    cout << "\n";
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