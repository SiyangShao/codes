// Connecting the Numbers
#include <bits/stdc++.h>
#include <queue>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 2 + 1), b(n * 2 + 1, 0);
    vector<vector<int>> mp(n + 1);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> a[i];
        mp[a[i]].emplace_back(i);
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (b[i] == 0) {
            auto l = mp[a[i]][0], r = mp[a[i]][1];
            while (!q.empty() && q.top() < l) {
                q.pop();
            }
            if (q.empty() || q.top() > r) {
                q.push(r);
                b[l] = 1, b[r] = 1;
            } else {
                b[l] = -1, b[r] = -1;
            }
        }
    }
    // for (int i = 1; i <= 2 * n; ++i) {
    //     cout << b[i] << " ";
    // }
    // cout << "\n";
    while (!q.empty()) {
        q.pop();
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (b[i] == -1) {
            auto l = mp[a[i]][0], r = mp[a[i]][1];
            while (!q.empty() && q.top() < l) {
                q.pop();
            }
            if (q.empty() || q.top() > r) {
                q.push(r);
                b[l] = 0, b[r] = 0;
            } else {
                cout << "no\n";
                return;
            }
        }
    }
    cout << "yes\n";
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