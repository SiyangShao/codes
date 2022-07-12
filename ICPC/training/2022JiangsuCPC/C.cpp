#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, q, p;
    cin >> n >> q >> p;
    vector<ll> a(n + n + 1);
    a[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = 0;
    }
    vector<ll> ans(n + 1);
    for (ll x = 1; x <= p; ++x) {
        deque<pair<ll, ll>> dq;
        dq.clear();
        dq.emplace_back(0, 0);
        // cout<<"x="<<x<<":\n";

        // output(last one) - x <= n
        for (ll k = x; k <= n; k += x) {
            while (!dq.empty() && dq.front().second + p < k) {
                dq.pop_front();
            }
            ll tmp = a[k] + dq.front().first;
            // cout<<k<<" "<<dq.front().second<<" "<<a[x]<<"\n";
            // dp[k] is (nxt)

            while (!dq.empty() && dq.back().first < tmp) {
                dq.pop_back();
            }
            dq.emplace_back(tmp, k);
        }
        // can jump to n+1, rather than the first element %x > n
        while (!dq.empty() && dq.front().second + p < n + 1) {
            dq.pop_front();
        }
        ans[x] = dq.front().first;

        // cout<<ans[x]<<"\n";
    }
    while (q--) {
        ll x;
        cin >> x;
        if (x > p) {
            cout << "Noob\n";
            continue;
        }
        cout << ans[x] << "\n";
    }
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