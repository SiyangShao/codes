#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16 + 7;
auto solve() {
    ll n;
    string s;
    cin >> n >> s;
    if (s[0] != '9') {
        for (auto i : s) {
            cout << '9' - i;
        }
        cout << "\n";
        return;
    }
    // begin is 1
    vector<ll> ans(n);
    ll d = 0;
    for (ll i = n - 1; i >= 0; --i) {
        ll minus = d + (s[i] - '0');
        if (1 >= minus) {
            d = 0;
            ans[i] = 1 - minus;
        } else {
            d = 1;
            ans[i] = 11 - minus;
        }
    }
    for (auto i : ans) {
        cout << i;
    }
    cout << "\n";
    return;
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