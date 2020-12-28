#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    if (s[0] == 'B') {
        cout << "NO\n";
        return;
    }
    if (s[s.size() - 1] != 'B') {
        cout << "NO\n";
        return;
    }
    ll A = 0, B = 0;
    for (auto &i : s) {
        if (i == 'A') {
            A++;
        } else {
            B++;
            if (A < B) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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