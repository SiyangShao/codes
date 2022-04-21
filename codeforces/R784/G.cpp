#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (ll i = 0; i < m; ++i) {
        // cout << i << "\n";
    again:
        bool flag = false;
        for (ll j = n - 2; j >= 0; --j) {
            if (a[j][i] == '*' && a[j + 1][i] == '.') {
                a[j][i] = '.';
                a[j + 1][i] = '*';
                flag = true;
            }
        }
        if (flag) {
            goto again;
        }
    }
    for (ll i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }
    // cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}