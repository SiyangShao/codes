#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n;
vector<string> mp;
void solve() {
    cin >> n >> m;
    mp.resize(n);
    for (auto &i : mp)
        cin >> i;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            int cnt = 0;
            if (mp[i][j] == '1')
                cnt++;
            if (mp[i][j + 1] == '1')
                cnt++;
            if (mp[i + 1][j] == '1')
                cnt++;
            if (mp[i + 1][j + 1] == '1')
                cnt++;
            if (cnt == 3) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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