#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<int> ans(n);
    vector<int> bug;
    vector<queue<int>> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        ans[i] = a[(i + 1) % n];
        if (ans[i] == a[i]) {
            bug.emplace_back(i);
        } else {
            pos[ans[i]].emplace(i);
        }
    }
    sort(bug.begin(), bug.end(), [&](int i, int j) { return a[i] < a[j]; });
    int l = 0, r = 0;
    for (auto b : bug) {
        auto now = a[b];
        r = max(r, now + 1);
        while (pos[r].empty()) {
            r++;
        }
        while (pos[l].empty()) {
            l++;
        }
        if (r <= n && !pos[r].empty()) {
            auto p = pos[r].front();
            pos[r].pop();
            swap(ans[b], ans[p]);
            continue;
        }

        if (l < now && !pos[l].empty()) {
            auto p = pos[l].front();
            pos[l].pop();
            swap(ans[b], ans[p]);
        }
    }
    for (auto i : ans) {
        cout << i << " ";
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