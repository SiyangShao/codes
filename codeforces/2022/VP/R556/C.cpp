#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll one = 0, two = 0;
    for (auto &i : a) {
        cin >> i;
        if (i == 1) {
            one++;
        } else {
            two++;
        }
    }
    assert(one + two == n);
    if (two == 0 || one == 0) {
        for (auto i : a) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    assert(n >= 2);
    cout << "2 1 ";
    two--, one--;
    for (ll i = 0; i < two; ++i) {
        cout << "2 ";
    }
    for (ll i = 0; i < one; ++i) {
        cout << "1 ";
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