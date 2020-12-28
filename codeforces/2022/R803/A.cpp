#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> exit(8);
    exit.assign(8, 0);
    for (auto &i : a) {
        cin >> i;
        ll cnt = 0, tmp = i;
        while (tmp) {
            if (tmp % 2 == 1) {
                exit[cnt]++;
            }
            cnt++;
            tmp /= 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        ll cnt = 0, tmp = a[i];
        bool flag = true;
        while (tmp) {
            if (tmp % 2 == 1) {
                if (exit[cnt] % 2 == 0) {

                } else {
                    flag = false;
                    break;
                }
            }
            tmp /= 2;
            cnt++;
        }
        if (flag) {
            cout << a[i] << "\n";
            return;
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