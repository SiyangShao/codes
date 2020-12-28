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
    for (ll i = 2; i < n; i += 2) {
        if (a[i] % 2 != a[0] % 2) {
            cout << "NO\n";
            return;
        }
    }
    for (ll i = 3; i < n; i += 2) {
        if (a[i] % 2 != a[1] % 2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}