#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
constexpr ll N = 200000 + 7;
ll n, m;
vector<ll> cnt(N, 0);
vector<ll> s(N, 0), t(N, 0);
vector<ll> fac(N, 0), inv(N, 0), inn(N, 0);
inline ll fp(ll x, ll y) {
    ll res = 1;
    while (y)
        res = (y & 1) ? res * x % mod : res, x = x * x % mod, y >>= 1;
    return res;
}
inline void init() {
    fac[0] = inv[0] = 1;
    for (ll i = 1; i < N; i++)
        inn[i] = fp(i, mod - 2);
    for (ll i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = fp(fac[N - 1], mod - 2);
    for (ll i = N - 2; i >= 1; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
inline ll C(ll n, ll m) {
    if (n < m || m < 0)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
inline ll A(ll n, ll m) {
    if (n < m || m < 0)
        return 0;
    return fac[n] * inv[n - m] % mod;
}
struct FenwickTree {
    vector<ll> bit;
    FenwickTree(ll n) { bit.resize(n + 1, 0); }
    void update(ll pos, ll val) {
        while (pos < bit.size()) {
            bit[pos] = (bit[pos] + val) % mod;
            pos += pos & -pos;
        }
    }
    ll query(ll pos) {
        ll res = 0;
        while (pos > 0) {
            res = (res + bit[pos]) % mod;
            pos -= pos & -pos;
        }
        return res;
    }
} tr(N);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        cnt[s[i]]++;
    }
    ll now = fac[n];
    for (ll i = 1; i < N; i++) {
        now = (now * inv[cnt[i]]) % mod;
        tr.update(i, cnt[i]);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> t[i];
    }
    ll sum = n;
    ll ans = 0, pd = 0;
    for (ll i = 1; i <= min(n, m); i++) {
        now *= inn[sum];
        now %= mod;
        ans += now * (tr.query(t[i] - 1)) % mod;
        ans %= mod;
        if (cnt[t[i]]) {
            tr.update(t[i], -cnt[t[i]]);
            now *= cnt[t[i]];
            now %= mod;
            sum--;
            cnt[t[i]]--;
            tr.update(t[i], cnt[t[i]]);
        } else {
            pd = 1;
            break;
        }
    }
    if (n < m && !pd)
        ans = (ans + 1) % mod;
    cout << ans << "\n";
}