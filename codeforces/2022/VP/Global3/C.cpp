#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10;
array<int, N> a, pos;
vector<pair<int, int>> ans;
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    auto op = [&](int x, int y) {
        ans.emplace_back(x, y);
        swap(pos[a[x]], pos[a[y]]);
        swap(a[x], a[y]);
    };
    for (int i = n / 2; i >= 1; --i) {
        int j = n - i + 1;
        if (pos[i] != i) {
            if (pos[i] < n / 2) {
                op(n, pos[i]);
            } else {
                op(1, pos[i]);
                op(n, 1);
            }
            op(pos[i], i);
        }
        if (pos[j] != j) {
            if (pos[j] > n / 2) {
                op(1, pos[j]);
            } else {
                op(n, pos[j]);
                op(n, 1);
            }
            op(pos[j], j);
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
        cout << x << " " << y << '\n';
}
auto main()->int {
    int _ = 1;
    while (_--) {
        solve();
    }
}