#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll N = 86400;
auto solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
        x -= i;
    }
    if (x == n - 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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