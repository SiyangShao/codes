#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAXN = 1e9 + 7;
vector<ll> dp;
auto init(ll i) -> void {
    auto res = dp.back();
    auto tmp = i / 3;
    if (i % 3 == 0) {
        res += tmp * 2 + tmp * 2;
    } else if (i % 3 == 1) {
        res += tmp * 2 + tmp * 2;
    } else {
        res += (tmp + 1) * 2 + tmp * 2;
    }
    dp.emplace_back(res);
    if (res < MAXN) {
        init(i + 1);
    }
}
auto solve() {
    ll t;
    cin >> t;
    auto pos = lower_bound(dp.begin(), dp.end(), t) - dp.begin();
    cout << pos << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    dp.emplace_back(0);
    dp.emplace_back(0);
    dp.emplace_back(2);
    dp.emplace_back(6);
    init(4);
    // cout<<dp.size()<<"\n";
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}