#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll l, r;
    cin >> l >> r;
    ll num = (r - l + 1);
    ll ans = num * (num - 1) * (num - 2) / 6;
    function<ll(ll)> cal = [&](ll u) {
        ll tmp = sqrt(u);
        ll cnt = 0;
        for (ll i = 1; i <= tmp; ++i) {
            if (u % i == 0) {
                if (i >= l && i < u)
                    cnt++;
                if (u / i >= l && u / i < u && u / i != i) {
                    cnt++;
                }
            }
        }
        return cnt * (cnt - 1) / 2;
    };
    function<ll(ll)> cal2 = [&](ll u) {
        if (u % 3 != 0 || u * 2 / 3 < l) {
            return 0LL;
        }
        ll cnt = 0;
        ll tmp = u * 2 / 3;
        if (u % 2 == 0 && u / 2 >= l) {
            if (u % tmp != 0)
                cnt++;
        }
        if (u % 5 == 0 && u * 2 / 5 >= l) {
            ll tmp2 = u * 2 / 5;
            if (u % tmp != 0 || u % tmp2 != 0)
                cnt++;
        }
        return cnt;
    };
    ll cnt1 = 0, cnt2 = 0;
    for (ll i = l; i <= r; ++i) {
        // cout<<cal(i)<<" "<<cal2(i)<<"\n";
        ans -= cal(i);
        ans -= cal2(i);
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