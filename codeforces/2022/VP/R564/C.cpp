#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), vis(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> b[i];
        vis[b[i]] = i;
    }
    ll ans = n * 2;
    if (vis[1]) {
        bool flag = true;
        for (ll i = vis[1] + 1; i <= n; ++i) {
            if (b[i] != i - vis[1] + 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ll cnt = 0;
            for (ll i = n - vis[1] + 2; i <= n; ++i) {
                if (vis[i] > cnt) {
                    cnt = n * 2;
                    break;
                }
                cnt++;
            }
            ans = min(ans, cnt);
        }
    }
    ll st = 0;
    for (ll i = 1; i <= n; ++i) {
        if (vis[i] && st + i - 1 < vis[i]) {
            st = vis[i] - i + 1;
        }
    }
    ans = min(ans, st+n);
    cout << ans << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--) {
        solve();
    }
}