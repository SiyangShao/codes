#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

void solve(){
    ll n; cin >> n;
    unordered_map<ll, ll> f;
    vector<ll> a(n + 1); FOR(i, 1, n) cin >> a[i];

    ll ans = 0;
    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            ll d = a[j] - a[i];
            ll nx = a[i] - d;
            ans += f[nx];
        }
        f[a[i]]++;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
