#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto cal(vector<ll> &a, ll n, ll k) {
    if (k >= n) {
        return accumulate(a.begin(), a.end(), 0LL) + (k - 1 + k - n) * n / 2;
    }
    ll ans = 0, cnt = 0;
    for (ll i = 0; i < k; ++i) {
        cnt += a[i];
    }
    ans = cnt;
    for (ll i = 0; i + k < n; ++i) {
        cnt -= a[i];
        cnt += a[i + k];
        ans = max(ans, cnt);
    }
    return ans + (0 + k - 1) * k / 2;
}
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), pre(n);
    for (auto &i : a) {
        cin >> i;
    }
    cout << cal(a, n, k) << "\n";
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