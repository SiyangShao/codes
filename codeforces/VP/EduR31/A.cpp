#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll N = 86400;
auto solve() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (ll i = 0; i < n; ++i) {
        if (t <= N - a[i]) {
            cout << i + 1 << "\n";
            return;
        }
        t -= N - a[i];
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