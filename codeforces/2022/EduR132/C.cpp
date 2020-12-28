#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(string &s) {
    ll n = s.length();
    ll cnt = 0;
    for (auto i : s) {
        if (i == '(') {
            cnt++;
        }
    }
    if (n % 2 || cnt * 2 > n) {
        return false;
    }
    ll rest = n / 2 - cnt;
    ll l = -1, r = -1;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '?' && rest != 0) {
            rest--;
            s[i] = '(';
            l = i;
        } else if (s[i] == '?') {
            r = i;
            break;
        }
    }
    ll all = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '(') {
            all++;
        } else if (s[i] == ')' || s[i] == '?') {
            all--;
        }
        if (all < 0) {
            return false;
        }
    }
    if (l == -1 || r == -1) {
        return true;
    }
    s[l] = ')', s[r] = '(';
    all = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '(') {
            all++;
        } else if (s[i] == ')' || s[i] == '?') {
            all--;
        }
        if (all < 0) {
            return true;
        }
    }
    return false;
}
auto solve() {
    string s;
    cin >> s;
    if (check(s)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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