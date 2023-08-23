#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
constexpr ll N = 1e6 + 7;
constexpr ll p = 1e9 + 7;
constexpr ll bs = 233;
ll len, q;
string s;
array<ll, N> Hash, Hash_reverse, qpow;
auto init() {
    qpow[0] = 1;
    for (ll i = 1; i < N; ++i) {
        qpow[i] = (qpow[i - 1] * bs) % p;
    }
    for (ll i = 1; i <= len; ++i) {
        Hash[i] = Hash[i - 1] * bs + s[i];
        Hash[i] %= p;
        Hash_reverse[i] = Hash_reverse[i - 1] * bs + s[len - i + 1];
        Hash_reverse[i] %= p;
    }
}
auto judge(ll L, ll R) {
    return (Hash[R] - (Hash[L - 1] * qpow[R - L + 1]) % p + p) % p ==
           (Hash_reverse[len - L + 1] -
            (Hash_reverse[len - R] * qpow[R - L + 1]) % p + p) %
               p;
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> len >> q;
    cin >> s;
    s = "_" + s;
    init();
    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (judge(l, r)) {
            cout << "Budada\n";
            continue;
        }
        if ((r - l) % 2 == 0) {
            cout << "Putata\n";
        } else {
            cout << "Budada\n";
        }
    }
}