#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll cnt = 0;
    char re = 'a', pre = 'a';
    for (auto i : s) {
        ll res = i - 'a';
        if (res <= cnt) {
            cout << "a";
            continue;
        }
        if (k == -1) {
            if (i <= pre) {
                cout << min(re, i);
            } else {
                cout << i;
            }
            continue;
        }
        if (res - cnt <= k) {
            auto tmp = res - cnt;
            k -= res - cnt;
            cnt = tmp;
            cout << "a";
        } else {
            cout << char(i - k);
            re = char(i - k);
            pre = i;
            k = -1;
        }
    }
    cout << "\n";
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