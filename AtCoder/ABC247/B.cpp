#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;
    vector<pair<string, string>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }
    for (int i = 0; i < n; ++i) {
        bool flag1 = true, flag2 = true;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            if (a[i].first == a[j].first || a[i].first == a[j].second) {
                flag1 = false;
            }
            if (a[i].second == a[j].second || a[i].second == a[j].first) {
                flag2 = false;
            }
        }
        if (flag1 || flag2) {
            continue;
        } else {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
auto main() -> int {
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}