#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
#define eb emplace_back
#define all0(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define ROF(i, a, b) for(ll i=(a); i>=(b); i--)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
int cnt[9][9][9][9][9][9][9][9];

void modSubset(const vl& v, const ll& d) {
    FOR(i1, 0, v[1]) FOR(i2, 0, v[2]) FOR(i3, 0, v[3])
    FOR(i4, 0, v[4]) FOR(i5, 0, v[5]) FOR(i6, 0, v[6])
    FOR(i7, 0, v[7]) FOR(i8, 0, v[8]) 
        cnt[i1][i2][i3][i4][i5][i6][i7][i8] += d;
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<vl> pcs;
    FOR(tq, 1, n) {
        string s; cin >> s;
        if (s[0] == 'C') {
            ll cnt; cin >> cnt;
            vl f(9);
            FOR(t, 1, cnt) {
                ll tot; cin >> tot;
                f[tot]++;
            }
            pcs.emplace_back(f);
            modSubset(f, 1);
        } else if (s[0] == 'D') {
            ll pcid; cin >> pcid;
            modSubset(pcs[pcid - 1], -1);
        } else {
            vl a(9); 
            ll tot; cin >> tot;
            FOR(t, 1, tot) {
                ll u; cin >> u;
                a[u]++;
            }
            cout << cnt[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]][a[8]] << '\n';
        }
    }
    cout.flush();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
