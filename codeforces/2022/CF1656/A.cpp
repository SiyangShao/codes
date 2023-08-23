#include <bits/stdc++.h>
using namespace std;
auto solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    int MIN = INT_MAX, MAX = INT_MIN, MI = 0, MA = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= MAX) {
            MAX = a[i];
            MA = i;
        }
        if (a[i] <= MIN) {
            MIN = a[i];
            MI = i;
        }
    }
    cout << MI + 1 << " " << MA + 1 << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
}