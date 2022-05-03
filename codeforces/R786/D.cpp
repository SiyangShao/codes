#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<int> c(n);
    for (int i = n - 1; i >= 0; i -= 2) {
        if (i == 0) {
            c[i] = a[i];
        } else {
            c[i] = max(a[i], a[i - 1]);
            c[i - 1] = min(a[i], a[i - 1]);
        }
    }
    auto judge = [&]() {
        for (int i = 1; i < n; ++i) {
            if (c[i] < c[i - 1])
                return false;
        }
        return true;
    };
    if (judge()) {
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