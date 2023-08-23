#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> one, zero;
ll num, n;
string s;
auto judge(ll val) {
    ll l = 0;
    ll r = lower_bound(zero.begin(), zero.end(), val) - zero.begin();
    while (l <= n && r <= n) {
        ll white = zero[r] - zero[l];
        ll black = num - (one[r] - one[l]);
        if (max(black, white) <= val) {
            return true;
        }
        if (r == n) {
            l++;
        } else {
            if (s[r + 1] == '0') {
                r++;
                while (s[l + 1] != '0') {
                    l++;
                }
                l++;
            } else {
                r++;
            }
        }
    }
    return false;
}
auto solve() {
    cin >> s;
    n = s.length();
    s = "_" + s;
    one.assign(n + 1, 0), zero.assign(n + 1, 0);
    num = 0;
    for (int i = 1; i <= n; ++i) {
        one[i] = one[i - 1], zero[i] = zero[i - 1];
        if (s[i] == '0') {
            zero[i]++;
        } else {
            num++;
            one[i]++;
        }
    }
    ll l = 0, r = n - num;
    ll mid = (l + r) / 2;
    while (l <= r) {
        mid = (l + r) / 2;
        if (judge(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (l >= 1 && judge(l - 1)) {
        cout << l - 1 << "\n";
    } else if (judge(l)) {
        cout << l << "\n";
    } else {
        cout << l + 1 << "\n";
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