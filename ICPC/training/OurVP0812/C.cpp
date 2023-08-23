#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(k);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end(), greater<>());
    function<bool(ll, ll)> check = [&](ll n, ll m) {
        bool flg = false;
        ll cnt = 0;
        for (auto i : a) {
            if (i / n > 2) {
                flg = true;
            }
            if (i / n >= 2) {
                cnt += i / n;
            }
        }
        return (cnt >= m) && (flg || m % 2 == 0);
    };
    if (check(n, m) || check(m, n)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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