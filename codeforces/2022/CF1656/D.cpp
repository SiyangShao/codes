#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
constexpr ll INF = 1e18;
vector<ll> twopow;
auto init() {
    ll cnt = 2;
    while (cnt < 2 * INF) {
        twopow.emplace_back(cnt);
        cnt *= 2;
    }
}
auto solve() {
    long long n;
    cin >> n;
    if (n % 2 == 1) {
        cout << "2\n";
        return;
    }
    ll tmp = n, cnt = 0;
    while (tmp % 2 == 0) {
        tmp /= 2;
        cnt++;
    }
    if (tmp == 1) {
        cout << "-1\n";
        return;
    }
    if ((twopow[cnt] + 1) * twopow[cnt] <= ll(2) * ll(n)) {
        // cout << (twopow[cnt] + 1) * twopow[cnt] << " ";
        cout << (long long)(twopow[cnt]) << "\n";
        return;
    } else {
        assert((tmp + 1) * tmp <= 2 * n);
        cout << (long long)(tmp) << "\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    int _;
    cin >> _;
    while (_--) {

        solve();
    }
}