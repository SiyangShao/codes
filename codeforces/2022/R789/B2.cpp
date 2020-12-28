#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
auto cal(ll n, string &s) {
    ll cnt = 1, ans = 0;
    auto pre = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] == pre) {
            cnt++;
        } else {
            if (cnt % 2 == 0) {
                cnt = 1;
                pre = s[i];
            } else {
                ans++;
                cnt = 2;
                pre = s[i];
            }
        }
    }
    assert(cnt % 2 == 0);
    return ans;
}
auto sol(ll n, const string &s) {
    ll cnt = 1, ans = 0, size = 1;
    auto pre = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] == pre) {
            cnt++;
        } else {
            if (cnt % 2 == 0) {
                cnt = 1;
                pre = s[i];
                size++;
            } else {
                ans++;
                // cnt = 2;
                // pre = s[i];
                if (cnt == 1) {
                    cnt = 2;
                    pre = s[i];
                    if (i != 1)
                        size--;
                } else {
                    cnt++;
                }
            }
        }
    }
    return size;
}
auto solve() {
    ll n = 6;
    cin >> n;
    string s;
    cin >> s;
    string pre, lst;
    if (s[0] == '0') {
        pre = "00";
    } else {
        pre = "11";
    }
    if (s[n - 1] == '1') {
        lst = "11";
    } else {
        lst = "00";
    }
    string another = pre + s + lst;
    auto tmp = cal(n, s);
    auto l = sol(n, s);
    reverse(s.begin(), s.end());
    auto r = sol(n, s);
    // cout << another << "\n";
    auto L = sol(another.length(), another);
    reverse(another.begin(), another.end());
    auto R = sol(another.length(), another);
    // cout << l << " " << r << " " << L << " " << R << "\n";
    cout << tmp << " " << min(min(l, r), min(L, R)) << "\n";
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