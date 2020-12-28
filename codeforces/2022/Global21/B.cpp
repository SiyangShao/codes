#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll zero = 0;
    for (auto &i : a) {
        cin >> i;
        if (i == 0) {
            zero++;
        }
    }
    if (zero == 0) {
        cout << "1\n";
    } else if (zero == n) {
        cout << "0\n";
    } else {
        ll L = 0, R = n - 1;
        for (; L < n; ++L) {
            if (a[L] != 0) {
                break;
            }
        }
        for (; R >= 0; --R) {
            if (a[R] != 0) {
                break;
            }
        }
        for (ll i = L; i < R; ++i) {
            if (a[i] == 0) {
                cout << "2\n";
                return;
            }
        }
        cout << "1\n";
    }
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