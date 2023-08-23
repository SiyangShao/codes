#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    string S, T;
    cin >> S >> T;
    if (S[0] != T[0] || S[n - 1] != T[n - 1]) {
        cout << "-1\n";
        return;
    }
    vector<pair<ll, ll>> s, t;
    ll cnt = 0, pre = 0;
    cnt = 1, pre = S[0] - '0';
    for (ll i = 1; i < n; ++i) {
        if (S[i] - '0' == pre) {
            cnt++;
        } else {
            s.emplace_back(pre, cnt);
            pre = S[i] - '0';
            cnt = 1;
        }
    }
    s.emplace_back(pre, cnt);
    cnt = 1, pre = T[0] - '0';
    for (ll i = 1; i < n; ++i) {
        if (T[i] - '0' == pre) {
            cnt++;
        } else {
            t.emplace_back(pre, cnt);
            pre = T[i] - '0';
            cnt = 1;
        }
    }
    t.emplace_back(pre, cnt);
    if (s.size() != t.size()) {
        cout << "-1\n";
        return;
    }
    ll m = s.size();
    ll ans = 0;
    for (ll i = 0; i < m; ++i) {
        if (s[i].first != t[i].first) {
            cout << "-1\n";
            return;
        }
    }
    ll dif = t[0].second - s[0].second;
    ans = abs(dif);
    for (ll i = 1; i < m; ++i) {
        s[i].second -= dif;
        dif = t[i].second - s[i].second;
        ans += abs(dif);
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