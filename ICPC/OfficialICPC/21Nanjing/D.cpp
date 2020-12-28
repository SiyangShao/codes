#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e5 + 7;
ll n;
array<ll, N> fw, vis, a;
auto lowbit(ll x) { return x & (-x); }
auto add(ll x) {
    while (x <= n) {
        fw[x]++;
        x += lowbit(x);
    }
}
auto sum(ll x) {
    auto tot = 0LL;
    while (x) {
        tot += fw[x];
        x -= lowbit(x);
    }
    return tot;
}
auto solve() {
    cin >> n;
    fw.fill(0);
    vis.fill(0);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    vis[a[1]] = 1;
    add(a[1]);
    ll mx = a[1];
    cout << ans;
    ll flag = 0;
    ll cnt = 0;
    for (ll i = 2; i <= n; ++i) {
        if (!vis[a[i]]) {
            vis[a[i]] = 1;
            add(a[i]);
        }
        if (a[i] == mx) {
            flag = true;
        }
        if (flag && a[i] <= mx) {
            cnt++;
        }
        if (a[i] > mx) {
            mx = a[i];
            ans += cnt + 2;
            cnt = 0, flag = false;
        } else {
            ans += sum(mx) - sum(a[i]);
        }
        cout << " " << ans;
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