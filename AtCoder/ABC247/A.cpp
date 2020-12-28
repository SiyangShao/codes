#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    cout << "0";
    for (int i = 0; i + 1 < s.size(); ++i) {
        cout << s[i];
    }
}
auto main() -> int {
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}