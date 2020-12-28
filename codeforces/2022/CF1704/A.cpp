#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    for (int i = 1; i < m; ++i) {
        if (b[i] != a[n - m + i]) {
            cout << "NO\n";
            return;
        }
    }
    if (b[0] == a[n - m]) {
        cout << "YES\n";
    } else {
        for (int i = 0; i < n - m; ++i) {
            if (a[i] == b[0]) {
                cout << "YES\n";
                return;
            }
        }
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