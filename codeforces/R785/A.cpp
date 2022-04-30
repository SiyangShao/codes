#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    if (s.length() % 2 == 0) {
        cout << "Alice ";
        ll cnt = 0;
        for (auto i : s) {
            cnt += i - 'a' + 1;
        }
        cout << cnt << "\n";
    } else {
        if (s.length() == 1) {
            cout << "Bob ";
            cout << s[0] - 'a' + 1 << "\n";
        } else {
            ll cnt = 0;
            for (auto i : s) {
                cnt += i - 'a' + 1;
            }
            cnt -= 2 * min(*s.begin() - 'a' + 1, *(s.end() - 1) - 'a' + 1);
            cout << "Alice ";
            cout << cnt << "\n";
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