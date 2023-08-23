#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n + 1), b(n + 1);
    a[0] = 0, b[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+')
            a[i + 1] = a[i] + 1, b[i + 1] = b[i];
        else
            a[i + 1] = a[i], b[i + 1] = b[i] + 1;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            auto plus = a[j] - a[i - 1];
            auto minus = b[j] - b[i - 1];
            if (minus >= plus && (minus - plus) % 3 == 0) {
                ans++;
            }
        }
    }
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