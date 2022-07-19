#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e5, INF = 1e15;
vector<ll> st;
vector<ll> base;
inline ll lg(ll x) {
    ll res = 0;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
}
inline ll merge(ll a, ll b) {
    ll B = lg(b), A = lg(a);
    if (A + B > 15) {
        return INF + 7;
    }
    return a * base[B] + b;
}
auto init() {
    ll bs = 1;
    while (bs <= INF) {
        base.emplace_back(bs);
        bs *= 10;
    }
    for (ll p = 1; p <= N; p++) {
        for (ll q = p + 1; p * q <= N; ++q) {
            if (gcd(p, q) != 1)
                continue;
            for (ll k = 1; p * q * k <= N; ++k) {
                ll x = k * p * p, y = k * p * q;
                ll num = merge(x, y);
                ll cur = y;
                while (cur % p == 0) {
                    cur /= p;
                    cur *= q;
                    num = merge(num, cur);
                    if (lg(num) > 15) {
                        break;
                    }
                    st.emplace_back(num);
                }
            }
        }
    }
    sort(st.begin(), st.end());
}
inline auto sol(ll u) {
    return upper_bound(st.begin(), st.end(), u) - st.begin();
}
auto solve() {
    ll L, R;
    cin >> L >> R;
    cout << sol(R) - sol(L - 1) << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    int _ = 1;
    cin >> _;
    ll t = 1;
    while (_--) {
        cout << "Case #" << t << ": ";
        t++;
        solve();
    }
}