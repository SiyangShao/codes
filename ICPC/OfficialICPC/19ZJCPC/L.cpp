#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

void solve(){
    ll n, m; cin >> n; 
    vector<ll> a(n + 1); FOR(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll ts = 0;
    ll ans = 0;
    FOR(i, 1, n) {
        ts += a[i];
        if (a[i] * i <= ts) continue; // such element does not exist
        ll lo = 1, hi = i; // find the first element greater than avg
        while (lo < hi) {
            ll mi = lo + hi >> 1;
            if (a[mi] * i > ts) hi = mi;
            else lo = mi + 1;
        }
        chkmax(ans, i - lo + 1);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
