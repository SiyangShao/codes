#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    auto ask = [&](ll x, ll y) {
        cout << "? " << x << " " << y << endl;
        ll tmp;
        cin >> tmp;
        return tmp - 1;
    };
    vector<ll> a(n, 0), b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = ask(0, i);
        a[b[i]]++;
    }
    if (*min_element(b.begin(), b.end()) == n - 1) {
        // a[0] == n;
        for (int i = 0; i < n; ++i) {
            ll tmp = ask(1, i);
            // a[1] != n
            if (tmp == n - 1) {
                cout << "! " << (i) % n << "\n";
                return;
            }
        }
    } else {
        // a[0] != n;
        ll b0 = -1;
        for (int i = 0; i < n; ++i) {
            if (b[i] == n - 1) {
                b0 = i;
                break;
            }
        }
        assert(b0 != -1);
        ll b1 = (b0 + 1) % n;
        for (int i = 0; i < n; ++i) {
            ll tmp = ask(i, b1);
            if (tmp == n - 1) {
                cout << "! " << (n + b0 - i) % n << "\n";
                return;
            }
        }
    }
}
auto main() -> int {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}