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
    stack<ll> MX, MI;
    while (!MX.empty()) {
        MX.pop();
    }
    while (!MI.empty()) {
        MI.pop();
    }
    for (ll i = n - 1; i >= 0; --i) {
        if (MX.empty() || a[i] > a[MX.top()]) {
            MX.emplace(i);
        }
        if (MI.empty() || a[i] < a[MI.top()]) {
            MI.emplace(i);
        }
    }
    ll pos = 0, ans = 0;
    while (pos < n - 1) {
        // cout << MX.top() << " " << MI.top() << " ";
        while (MX.top() <= pos) {
            MX.pop();
        }
        while (MI.top() <= pos) {
            MI.pop();
        }
        ll R = pos + 1;
        if (a[R] > a[pos]) {
            ll mx = a[R];
            for (ll j = R; j <= MX.top(); ++j) {
                if (a[j] > mx) {
                    mx = a[j];
                    R = j;
                } else if (a[j] < a[pos]) {
                    break;
                }
            }
        } else {
            ll mx = a[R];
            for (ll j = R; j <= MI.top(); ++j) {
                if (a[j] < mx) {
                    mx = a[j];
                    R = j;
                } else if (a[j] > a[pos]) {
                    break;
                }
            }
        }
        pos = R;
        ans++;
    }
    cout << ans << "\n";
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