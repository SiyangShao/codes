#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using point = pair<ld, ld>;
constexpr ld PI = 3.14159265358979323846;
point rotate(point p, ld t) {
    auto [x, y] = p;

    return {x * cos(t) + y * -sin(t), x * sin(t) + y * cos(t)};
}
auto solve() {
    double a, b;
    ll d;
    cin >> a >> b >> d;
    ld t = PI * d / 180.0;
    auto p = rotate({a, b}, t);
    cout << setprecision(12);
    cout << p.first << " " << p.second << "\n";
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