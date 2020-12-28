#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
array<int, N> a, ps;
int n, k;
auto solve() {
    cin >> n >> k;
    ps.fill(0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int tmp = N + a[i];
        for (int j = 1; j <= min(a[i], k); j = (a[i] / (a[i] / j)) + 1) {
            int nv = a[i] / j;
            ps[nv + 1] = max(ps[nv + 1], tmp);
            tmp = nv;
        }
        ps[0] = max(ps[0], tmp);
    }
    int ans = N, cm = 0;
    for (int i = 0; i <= a[0]; ++i) {
        cm = max(cm, ps[i]);
        ans = min(ans, cm - i);
    }
    cout << ans << "\n";
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