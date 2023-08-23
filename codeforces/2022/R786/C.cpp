#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string a, t;
    cin >> a >> t;
    if (t == "a") {
        cout << "1\n";
        return;
    }
    bool flag = false;
    for (auto i : t) {
        if (i == 'a') {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << "-1\n";
        return;
    }
    auto ans = 1LL << a.size();
    cout << ans << "\n";
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