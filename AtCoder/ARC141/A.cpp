#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
array<ll, 20> bs;
auto len(auto n) {
    ll len = 0;
    while (n) {
        len++;
        n /= 10;
    }
    return len;
}
auto solve() {
    ll x;
    cin >> x;
    ll n = len(x);
    ll ans = 9;
    while (ans <= x) {
        ans = ans * 10 + 9;
    }
    ans /= 10;
    for (ll i = 1; i < n; ++i) {
        if (n % i == 0) {
            ll l = n / i;
            ll now = x / bs[n - i];
            ll now2 = now - 1;
            for (ll j = 1; j < l; ++j) {
                now = now * bs[i] + now % bs[i];
                now2 = now2 * bs[i] + now2 % bs[i];
            }
            if (now <= x) {
                ans = max(ans, now);
            }
            ans = max(ans, now2);
        }
    }
    cout << ans << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    bs[0] = 1;
    for (ll i = 1; i < 20; ++i) {
        bs[i] = bs[i - 1] * 10;
    }
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}