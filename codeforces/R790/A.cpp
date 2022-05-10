#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 我走在每天必须面对的分岔路
// 我怀念过去单纯美好的小幸福
auto solve() {
    string s;
    cin >> s;
    if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5]) {
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