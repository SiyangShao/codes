#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 2, 0), dif(n + 2, 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (ll i = 1; i <= n + 1; ++i) {
        dif[i] = a[i] - a[i - 1];
    }
    for (ll i = 1; i <= n + 1; ++i) {
        if (dif[i] < 0) {
            cout << "No\n";
            return;
        }
        if (dif[i] == 0)
            continue;
        for (ll j = i + 3; j <= min(i + 5, n + 1); ++j) {
            if (dif[j] < 0) {
                if (abs(dif[j]) > dif[i]) {
                    dif[j] += dif[i];
                    dif[i] = 0;
                    break;
                } else {
                    dif[i] += dif[j];
                    dif[j] = 0;
                }
            }
        }
        if (dif[i] > 0) {
            if (i + 3 + 3 <= n + 1) {
                dif[i + 3] += dif[i];
                dif[i] = 0;
            } else if (i + 3 <= n + 1) {
                dif[n + 1] += dif[i];
                dif[i] = 0;
            } else {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    ll t = 1;
    while (_--) {
        cout << "Case #" << t << ": ";
        t++;
        solve();
    }
}