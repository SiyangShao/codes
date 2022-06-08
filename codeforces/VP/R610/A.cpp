#include <any>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b, c, r;
    cin >> a >> b >> c >> r;
    ll L = c - r, R = c + r;
    if (a > b)
        swap(a, b);
    if (L <= b && L >= a && R <= b && R >= a) {
        cout << b - a - r * 2 << "\n";
    } else {
        if (L >= b || R <= a) {
            cout << b - a << "\n";
        } else {
            if (L <= a && R >= b) {
                cout << 0 << "\n";
            } else {
                if (L <= a) {
                    cout << b - R << "\n";
                } else {
                    cout << L - a << "\n";
                }
            }
        }
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