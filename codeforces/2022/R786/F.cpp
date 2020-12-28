#include <array>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1010;
array<array<ll, N>, N> mp;
array<ll, N> lst;
auto solve() {
    ll n, m, q, sum = 0;
    ;
    cin >> n >> m >> q;
    vector<string> s(n);
    for (auto &i : s) {
        cin >> i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            mp[i][j] = s[i - 1][j - 1] == '*' ? 1 : 0;
            lst[j] += mp[i][j];
            sum += mp[i][j];
        }
    }
    auto judge = [&]() {
        ll c = sum / n, r = sum % n;
        ll t = 0;
        for (int j = 1; j <= c; ++j) {
            t += lst[j];
        }
        for (int i = 1; i <= r; ++i) {
            t += mp[i][c + 1];
        }
        return t;
    };
    while (q--) {
        ll x, y;
        cin >> x >> y;
        if (mp[x][y] == 1) {
            mp[x][y] = 0;
            lst[y]--;
            sum--;
        } else {
            mp[x][y] = 1;
            lst[y]++;
            sum++;
        }
        cout << sum - judge() << "\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}