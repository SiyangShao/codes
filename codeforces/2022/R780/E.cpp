#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll one = 0;
    for (const auto& i : a) {
        for (auto j : i) {
            one += (j == '1');
        }
    }
    vector<vector<int>> mp(n * 3 + 1, vector<int>(n * 3 + 1));
    for (int i = 0; i <= 3 * n; ++i) {
        for (int j = 0; j <= 3 * n; ++j) {
            if (i != 3 * n && j != 3 * n)
                mp[i][j] = a[i % n][j % n] - '0';
            if (i != 0 && j != 0) {
                mp[i][j] += mp[i - 1][j - 1];
            }
        }
    }
    ll ans = 0;
    for (int i = n; i <= 3 * n; ++i) {
        for (int j = n; j <= 3 * n; ++j) {
            ll cnt = mp[i][j] - mp[i - n][j - n];
            ans = max(ans, cnt);
        }
    }
    cout << (n - ans) + (one - ans) << "\n";
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