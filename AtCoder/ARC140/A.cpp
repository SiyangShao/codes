#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr ll N = 2010, INF = 1e16;
auto solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> mp(n + 1, INF);
    for (ll t = 1; t <= n; t++) {
        if (n % t != 0)
            continue;
        ll pre = 0;
        ll i = n / t;
        for (ll j = 0; j < t; j++) {
            vector<ll> cnt(26, 0);
            cnt.assign(26, 0);
            for (ll l = 0; l < i; l++)
                cnt[s[j + l * t] - 'a']++;
            ll maxn = 0;
            for (ll m = 0; m < 26; m++)
                maxn = max(maxn, cnt[m]);
            pre += i - maxn;
            mp[t] = min(mp[t], pre);
        }
        for (ll i = 1; i <= n; i++) {
            if (k >= mp[i]) {
                cout << i << "\n";
                return;
            }
        }
    }
    cout << n << "\n";
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