#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
vector<ll> a, pre, lst;
auto judge(ll L, ll R) {
    // L is the maximum, R is the minimum
    /**
    lst[L-1] - lst[R] + k * pre[R] - pre[L-1] = (lst[n] - (lst[R] - lst[L-1])) +
    k * (pre[n] - (pre[R] - pre[L-1]))
    **/
    auto seg_sum = lst[L] - lst[R],
         else_sum = lst[n] - (lst[R] - lst[L]);
    auto seg_num = pre[R] - pre[L],
         else_num = pre[n] - (pre[R] - pre[L]);
    // if (seg_sum + pre[n] * k < else_sum || seg_sum - pre[n] * k > else_sum) {
    //     return -1LL;
    // }
    return min(seg_sum + seg_num * k, else_sum + else_num * k);
}
auto solve() {
    cin >> n >> k;
    a.assign(n + 1, 0);
    pre.assign(n + 1, 0);
    lst.assign(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        lst[i] = lst[i - 1] + a[i];
        pre[i] = pre[i - 1];
        if (a[i] == 0) {
            pre[i]++;
        }
    }
    if (abs(lst[n] - lst[0]) > (pre[n] - pre[0]) * k) {
        cout << "-1\n";
        return;
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i + 1; j <= n; ++j) {
            ans = max(ans, judge(i, j));
        }
    }
    for (ll i = 1; i <= n; ++i) {
        a[i] = -a[i];
        lst[i] = -lst[i];
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i + 1; j <= n; ++j) {
            ans = max(ans, judge(i, j));
        }
    }
    cout << ans + 1 << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}