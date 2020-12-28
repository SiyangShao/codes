#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        a[i].emplace_back(x);
        a[i].emplace_back(y);
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            a[i].emplace_back(1);
        } else {
            a[i].emplace_back(-1);
        }
    }
    sort(a.begin(), a.end(), [](auto x, auto y) {
        if (x[1] != y[1]) {
            return x[1] > y[1];
        } else {
            return x[0] < y[0];
        };
    });
    bool flag = false;
    if (a[0][2] == 1)
        flag = true;
    for (int i = 1; i < n; ++i) {
        if (a[i][1] != a[i - 1][1]) {
            if (a[i][2] == 1)
                flag = true;
            else
                flag = false;
            continue;
        }
        if (a[i][2] == 1) {
            flag = true;
        } else {
            if (flag) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}