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
    if (a[0] < 0 || accumulate(a.begin(), a.end(), 0) != 0) {
        cout << "No\n";
        return;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += a[i];
        if (ans < 0) {
            cout << "No\n";
            return;
        } else if (ans > 0) {
            continue;
        } else {
            for (ll j = i + 1; j < n; ++j) {
                if (a[j] != 0) {
                    cout << "No\n";
                    return;
                }
            }
            cout << "Yes\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
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