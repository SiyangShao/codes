#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
// a[1], a[2], a[3]
void solve(){
    ll n; cin >> n;
    vector<ll> l(n + 1); FOR(i, 1, n) cin >> l[i];
    vector<ll> d(n + 1); FOR(i, 1, n - 1) d[i] = l[i + 1] - l[i];
    vector<ll> g(n + 1); FOR(i, 1, n) cin >> g[i];
    sort(g.begin() + 1, g.end());
    vector<ll> coeff(n + 1);
    FOR(i, 2, n) coeff[i] = d[i - 1] - coeff[i - 1];
    
    // x_i = (-1)^(i+1) * x_1 + coeff[i]   
    vector<ll> candx;
    // x, x+c[3], x+c[5] ... min(x + c[]) = x + min(c[]) = x_min ==> x_min - min(c[])
    ll t = 1e16;
    for (ll i = 1; i <= n; i += 2) chkmin(t, g[1] - coeff[i]);
    candx.emplace_back(t); t = 1e16;
    // min(-x+c[])=min_x --> min(c[])-x=min_x  min(c[]) - min_x = x
    for (ll i = 2; i <= n; i += 2) chkmin(t, coeff[i] - g[1]);
    candx.emplace_back(t);
    t = 0;
    for (ll i = 1; i <= n; i += 2)
      chkmax(t, g[n] - coeff[i]);
    candx.emplace_back(t);
    t = 0;
    for (ll i = 2; i <= n; i += 2)
      chkmax(t, coeff[i] - g[n]);
    candx.emplace_back(t);
    for (auto x: candx) {
        multiset<ll> s;
        FOR(i, 1, n) s.emplace(g[i]);
        bool gg = false;
        FOR(i, 1, n) {
            ll val = x * (i % 2 == 1 ? 1 : -1) + coeff[i];
            if (s.find(val) == s.end()) gg = true;
            else s.erase(s.find(val));
        }
        if (!gg) {
            FOR(i, 1, n) cout << x * (i % 2 == 1 ? 1 : -1) + coeff[i] << " ";
            cout << '\n';
            return;
        }
    }
    assert(false);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T_ = 1;
    // cin >> T_;
    while (T_--) solve();
    return 0;
}
