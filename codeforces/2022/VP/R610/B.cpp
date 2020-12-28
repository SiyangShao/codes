#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, p, k;
    cin >> n >> p >> k;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    ll pre = 0, sum = 0, answer = 0;
    for (ll i = 0; i <= k; ++i) {
        sum = pre;
        ll cnt = sum;
        if (cnt > p) {
            break;
        }
        ll ans = i;
        for (ll j = i; j + k - 1 < n; j += k) {
            if (cnt + a[j + k - 1] <= p) {
                cnt += a[j + k - 1];
                ans += k;
            } else {
                break;
            }
        }
        answer = max(ans, answer);
        sum += a[i];
        pre = sum;
    }
    cout << answer << "\n";
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