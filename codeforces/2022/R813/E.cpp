#include <bits/stdc++.h>
#include <random>
using namespace std;
using ll = long long;
auto solve() {
    ll num = 0, cnt = 0;
    ll cnt1 = 0, cnt2 = 0;
    for (ll i = 8; i <= 86; ++i) {
        for (ll k = i + 1; k <= 86; ++k) {
            for (ll j = i + 1; j < k; ++j) {
                num++;
                if (lcm(lcm(i, j), k) >= i + j + k) {
                    // cout<<i<<" "<<j<<" "<<k<<"\n";
                    cnt++;
                  
                } else {
                   if ((k % i == 0 && k % j == 0) ||(k == 1.5 * j && (k == 2 * i || k == 2.5 * i))) {
                        cnt1++;
                    }
                    if ((k == 1.5 * j && (k == 2 * i || k == 2.5 * i))) {
                        cnt2++;
                    }
                }
            }
        }
    }
    cout << num << " " << cnt << "\n";
    cout<<cnt1<<" "<<cnt2<<"\n";
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