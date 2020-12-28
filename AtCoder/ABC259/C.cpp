#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s, t;
    cin >> s >> t;
    vector<pair<ll, ll>> S, T;
    ll cur = s[0] - 'a', num = 1;
    for (ll i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            num++;
        } else {
            S.emplace_back(cur, num);
            cur = s[i] - 'a';
            num = 1;
        }
    }
    S.emplace_back(cur, num);
    cur = t[0] - 'a', num = 1;
    for (ll i = 1; i < t.length(); ++i) {
        if (t[i] == t[i - 1]) {
            num++;
        } else {
            T.emplace_back(cur, num);
            cur = t[i] - 'a';
            num = 1;
        }
    }
    T.emplace_back(cur, num);

    if (S.size() != T.size()) {
        cout << "No\n";
        return;
    }
    ll n = S.size();
    for (ll i = 0; i < n; ++i) {
        if (S[i].first != T[i].first) {
            cout << "No\n";
            return;
        }
        if (S[i].second == T[i].second)
            continue;
        if (S[i].second < T[i].second && S[i].second != 1)
            continue;
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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