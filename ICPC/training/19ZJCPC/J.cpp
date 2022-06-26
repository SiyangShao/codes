#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using point = pair<ld, ld>;
constexpr ld PI = 3.14159265358979323846;
constexpr ld THREE = 2.2935305746083123;
ld _rotate;
ld xa, ya, xb, yb;

point rotate(point p, ld t) {
    auto [x, y] = p;

    return {x * xa + y * ya, x * xb + y * yb};
}

auto output(point p) {
    p = rotate(p, _rotate);
    cout << p.first << " " << p.second << "\n";
}

auto solve() {
    ll d_s, d_t;
    cin >> d_s >> d_t;
    _rotate = PI * d_s / 180.0;
    xa = cos(_rotate), ya = -sin(_rotate), xb = sin(_rotate), yb = cos(_rotate);
    d_t = (d_t - d_s + 360) % 360;
    d_s = 0;
    if (d_t > 180) {
        ya = -ya, yb = -yb;
        d_t = 360 - d_t;
    }
    if (d_t == 0) {
        cout << "0\n";
        output({1, 0});
    } else if (d_t <= 90) {
        cout << "2\n";
        output({1, 0});
        ld theta = d_t * PI / 180;
        output({1 + cos(theta), sin(theta)});
        output({cos(theta), sin(theta)});
    } else if (d_t < 132) {
        cout << "3\n";
        point cur = {1, 0};
        output(cur);
        ld theta = d_t * PI / 180;
        ld alpha = PI - asin(sin(theta / 2.0) - 0.5) - theta / 2;
        ld beta = PI / 2.0 + (2 * PI - theta) / 2.0;
        cur.first -= cos(alpha);
        cur.second += sin(alpha);
        output(cur);
        cur.first += cos(beta);
        cur.second -= sin(beta);
        output(cur);
        output({cos(theta), sin(theta)});
    } else {
        cout << "4\n";
        output({1, 0});
        output({1, 1});
        output({0, 1});
        ld theta = d_t * PI / 180;
        output({cos(theta), 1 + sin(theta)});
        output({cos(theta), sin(theta)});
    }
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    cout << setprecision(14);
    while (_--) {
        solve();
    }
}