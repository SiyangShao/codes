#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll cur = -1, pre = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre ^= a[i];
        if (pre == 0 && i % 2 == 0) {
            cur = i + 1;
        }
    }
    if (pre == 1 || (cur == -1 && n % 2 == 0)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<ll> ans;
        if (n % 2 == 1) {
            for (ll i = 1; i + 2 <= n; i += 2) {
                ans.emplace_back(i);
            }
        } else {
            for (ll i = 1; i + 2 <= cur; i += 2) {
                ans.emplace_back(i);
            }
            for (ll i = cur + 1; i + 2 <= n; i += 2) {
                ans.emplace_back(i);
            }
        }
        cout << ans.size() * 2 << "\n";
        for (auto i : ans) {
            cout << i << " ";
        }
        for (auto i = ans.rbegin(); i < ans.rend(); ++i) {
            cout << *i << " \n"[i == ans.rend() - 1];
        }
    }
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