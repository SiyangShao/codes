#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
ll n, m;
auto qpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = (ret * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}
int main() {
    ll m, n;
    cin >> m >> n;
    if (m < n) {
        cout << "0\n";
    } else if (m == n) {
        cout << "1\n";
    } else {
        ll rest = m - n + 1;
        ll ans = qpow(n, m - n);
        cout << ans * rest * rest % MOD;
    }
}