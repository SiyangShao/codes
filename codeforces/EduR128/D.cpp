#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k, ans, cnt;
vector<ll> a;
auto solve() {
    cin >> n >> k;
    a.resize(n);
    ans = 0, cnt = 0;
    for (auto &i : a) {
        cin >> i;
        ans += i;
        if (i == 0) {
            cnt++;
        }
    }
    if (abs(ans) > cnt * k) {
        cout << "-1\n";
        return;
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