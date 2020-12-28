#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), cnt(k);
    cnt.assign(k, 0);
    ll ans = 0;
    for (auto &i : a) {
        cin >> i;
        cnt[i % k]++;
        ans += i / k;
    }
    ll l = 1;
    for (ll i = k - 1; i >= 1; --i) {
        if (cnt[i] == 0)
            continue;
        while (l < i) {
            auto mi = min(cnt[i], cnt[l]);
            cnt[i] -= mi;
            cnt[l] -= mi;
            if (l + i >= k) {
                ans += mi;
            } else {
                cnt[l] = 0;
                cnt[i] += mi;
            }
            if (cnt[l] == 0)
                l++;
            else
                break;
        }
        if (l == i) {
            if (l + i >= k)
                ans += cnt[i] / 2;
            break;
        }
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