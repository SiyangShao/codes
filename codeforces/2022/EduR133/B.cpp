#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        int cur = 2;
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                cout << "1 ";
            } else {
                cout << cur << " ";
                cur++;
            }
        }
        cout << "\n";
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