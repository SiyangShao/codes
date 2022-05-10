#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
// 我走在每天必须面对的分岔路
// 我怀念过去单纯美好的小幸福
auto solve() {
    ll n;
    cin >> n;
    ll cnt = LONG_LONG_MAX;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
        cnt = min(cnt, i);
    }
    ll ans = 0;
    for (auto i : a) {
        ans += i - cnt;
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