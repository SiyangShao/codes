#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll L, R;
auto check(ll mid) {
    // Check whehther it's in L-R
    cout << "? " << L << " " << mid << endl;
    ll cnt = 0;
    for (ll i = L; i <= mid; ++i) {
        ll tmp;
        cin >> tmp;
        if (tmp >= L && tmp <= mid) {
            cnt++;
        }
    }
    if (cnt % 2 == 0) {
        return false;
    } else {
        return true;
    }
}
auto solve() {
    ll n;
    cin >> n;
    L = 1, R = n;
    while (L < R) {
        ll mid = (L + R) / 2;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << "! " << L << "\n";
}
auto main() -> int {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}
