#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<ll> col(n * m), ans(m), row(n * m);
    col.assign(n * m, 0);
    ans.assign(m, 0);
    row.assign(n * m, 0);
    col[0] = row[0] = (s[0] == '1' ? 1 : 0);
    ll flag = -1;
    if (s[0] == '1') {
        ans[0] = 1;
        flag = 0;
    }
    for (int i = 1; i < n * m; ++i) {
        col[i] = col[i - 1];
        if (s[i] == '1' && ans[i % m] == 0) {
            col[i]++;
            ans[i % m] = 1;
        }
    }
    for (int i = 1; i < m; ++i) {
        row[i] = row[i - 1];
        if (s[i] == '1' && flag == -1) {
            flag = i;
            row[i] = row[i - 1] + 1;
        } else if (s[i] == '1') {
            flag = i;
        }
    }
    for (int i = m; i < n * m; ++i) {
        row[i] = row[i - m];
        if (s[i] == '1') {
            flag = i;
            row[i]++;
        } else {
            if (i - flag < m) {
                row[i]++;
            }
        }
    }
    for (int i = 0; i < n * m; ++i) {
        cout << col[i] + row[i] << " ";
    }
    cout << "\n";
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