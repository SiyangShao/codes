#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    string s;
    cin >> n >> s;
    ll cnt = 0;
    for (auto i : s) {
        cnt += i - '0';
    }
    if (cnt % 2 == 0 && cnt != 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        return;
    }
    ll begin = -1;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '1') {
            begin = (i + 1) % n;
            break;
        }
    }
    ll end = begin + n - 1;
    while (s[(end - 1) % n] == '0') {
        end--;
    }
    auto output = [&](ll l, ll r) {
        cout << (l % n) + 1 << " " << (r % n) + 1 << "\n";
    };
    ll num = 0;
    for (ll i = begin; i < begin + n; ++i) {
        if (s[i % n] == '0') {
            output(i, i + 1);
            if (num == 0 && i != end) {
                output(i, end);
            }
            num++;
        } else {
            if (num == 0 && i + 1 != begin + n && i != end) {
                output(i, end);
            }
            num = 0;
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