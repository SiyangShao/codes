#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(k);
    ll sum = n * m;
    for (auto &i : a) {
        cin >> i;
    }
    function<bool(int, int)> check = [&](int n, int m) {
        bool flag = false;
        ll tot = 0;
        for (auto i : a) {
            if (i / n > 2) {
                flag = true;
            }
            if (i / n >= 2) {
                tot += i / n;
            }
        }
        if (tot >= m && (flag || m % 2 == 0)) {
            return true;
        } else {
            return false;
        }
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