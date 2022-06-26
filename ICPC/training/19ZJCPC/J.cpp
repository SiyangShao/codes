#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define M_PI PI
using point = pair<ld, ld>;
constexpr ld PI = 3.14159265358979323846;
constexpr ld THREE = 2.2935305746083123;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

#define EPS 1e-8
#define EQ(a, b) (fabsl(a - b) <= EPS)
#define GEQ(a, b) (EQ(a, b) || a > b)
#define LEQ(a, b) (EQ(a, b) || a < b)
#define GT(a, b) (!EQ(a, b) && a > b)
#define LT(a, b) (!EQ(a, b) && a < b)

#define p2f pair<ld, ld>
ld _rotate;
ld xa, ya, xb, yb;
point rotate(point p, ld t) {
    auto [x, y] = p;

    return {x * xa - y * ya, x * xb + y * yb};
}
auto output(point p) {
    p = rotate(p, _rotate);
    cout << p.first << " " << p.second << "\n";
}
namespace three {
p2f rotate(const p2f &p, ld t) {
    auto [x, y] = p;
    return make_pair(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t));
}

void outputAnswer(const vector<p2f> &pts, const ld &theta) {
    cout << (signed)pts.size() - 1 << '\n';
    for (const auto &p : pts) {
        auto [x, y] = rotate(p, theta);
        cout << fixed << setprecision(16) << x << " " << y << '\n';
    }
}

void solve(ll ids, ll idt) {
    ld ds = (ld)ids * M_PI / 180.0, dt = (ld)idt * M_PI / 180.0;

    if (ids == idt)
        outputAnswer({{1, 0}}, ds);
    else {
        // 1. rotate everything by -ds degree, and normalize dt into [-pi, pi]
        dt -= ds;
        if (GEQ(dt, M_PI))
            dt = dt - 2.0 * M_PI; // boundary is ok

        // 2. ans == 2, iff degree in +- pi / 2
        if (LEQ(dt, M_PI / 2.0) && GEQ(dt, -M_PI / 2.0)) {
            vector<p2f> ans = {
                {1, 0}, {1 + cosl(dt), sinl(dt)}, {cosl(dt), sinl(dt)}};
            outputAnswer(ans, ds);
            return;
        }

        // 3. ans == 3, iff degree in +- ;
        const ld magicAngle = 2.2935305746083123;
        if (abs(ids - idt) <= 131) {
            ld c = sqrtl(3.0 - 2.0 * sqrtl(2.0) * cosl(dt - M_PI / 4.0));
            ld theta1 = acosl((1.0 + c * c - 2.0) / (2.0 * c));
            ld theta2 = acosl((1.0 + c * c - 1.0) / (2.0 * c));
            ld theta = theta1 + theta2;
            ld theta3 = 2.0 * M_PI - (dt - M_PI / 4.0) - theta1;
            ld forPoint = theta2 + theta3 - M_PI / 4.0;
            assert(GEQ(theta, M_PI / 2.0));

            vector<p2f> ans;
            if (GEQ(dt, 0))
                ans = {{1, 0},
                       {1, 1},
                       {1 - cosl(forPoint), 1 + sinl(forPoint)},
                       {cosl(dt), sinl(dt)}};
            else
                ans = {{1, 0},
                       {1, -1},
                       {1 - cosl(forPoint), -1 - sinl(forPoint)},
                       {cosl(dt), sinl(dt)}};
            outputAnswer(ans, ds);
            return;
        }

        // 4. ans == 4, iff otherwise
        vector<p2f> ans = {{1, 0}};
        if (GEQ(dt, 0)) {
            ans.emplace_back(1, 1), ans.emplace_back(0, 1);
            ans.emplace_back(cosl(dt), sinl(dt) + 1.0),
                ans.emplace_back(cosl(dt), sinl(dt));
        } else {
            ans.emplace_back(1, -1), ans.emplace_back(0, -1);
            ans.emplace_back(cosl(dt), -1.0 + sinl(dt)),
                ans.emplace_back(cosl(dt), sinl(dt));
        }
        outputAnswer(ans, ds);
    }

    cout.flush();
}
}; // namespace three
auto solve() {
    ll d_s, d_t;
    ll iid, iit;
    cin >> d_s >> d_t;
    iid = d_s, iit = d_t;
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
        // three::solve(iid, iit);
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