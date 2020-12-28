#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (auto &i : mp) {
        cin >> i;
    }
    if (mp[0][0] == '1') {
        cout << "-1"
             << "\n";
        return;
    }
    vector<vector<int>> ans;
    for (int i = m - 1; i >= 1; --i) {
        for (int j = 0; j < n; ++j) {
            if (mp[j][i] == '1') {
                ans.push_back({j, i - 1, j, i});
            }
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        if (mp[i][0] == '1') {
            ans.push_back({i - 1, 0, i, 0});
        }
    }
    cout << ans.size() << "\n";
    for (auto &i : ans) {
        cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] + 1 << " "
             << i[3] + 1 << "\n";
    }
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