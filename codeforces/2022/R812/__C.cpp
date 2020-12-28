#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array<ll, 100010> pos;
auto cal(ll n) {
    ll s = sqrt(n - 1);
    if (s * s == n - 1) {
        for (ll i = 0; i < n; ++i) {
            pos[i] = n - 1 - i;
        }
        return true;
    }
    s++;
    s *= s;
    ll beg = s - (n - 1);
    // cout<<beg<<" ";
    if (beg >= n) {
        return false;
    }
    for (ll i = beg; i < n; ++i) {
        pos[i] = s - i;
    }
    if (beg == 0) {
        return true;
    }
    return cal(beg);
}
auto solve() {
    ll n;
    cin >> n;
    if (!cal(n)) {
        cout << "-1\n";
    } else {
        for (ll i = 0; i < n; ++i) {
            cout << pos[i] << " ";
        }
        cout << "\n";
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