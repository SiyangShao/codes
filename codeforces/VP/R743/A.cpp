#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;

    ll cnt = 0;
    string s;
    cin >> s;
    for (auto &i : s) {
        if (i != '0') {
            cnt += i - '0' + 1;
        }
    }
    if (s[n - 1] != '0') {
        cnt--;
    }
    cout << cnt << "\n";
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