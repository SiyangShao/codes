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
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    sort(a.begin(), a.end());
    vector<ll> pos(n);
    for (ll i = 0; i < n / 2; ++i) {
        pos[i * 2] = a[i];
        pos[i * 2 + 1] = a[i + n / 2];
    }
    for (ll i = 0; i < n; ++i) {
        if ((pos[i] > pos[(i + 1) % n] && pos[i] > pos[(i - 1 + n) % n]) ||
            (pos[i] < pos[(i + 1) % n] && pos[i] < pos[(i - 1 + n) % n])) {
            continue;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (auto i : pos) {
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