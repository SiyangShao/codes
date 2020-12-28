#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

void solve(){
    ll n; cin >> n;
    ll xMin = 1e16, xMax = -1e16, yMin = 1e16, yMax = -1e16;
    FOR(i, 1, n) {
        ll u, v, h; cin >> u >> v >> h;
        chkmin(xMin, u - h), chkmin(yMin, v - h);
        chkmax(xMax, u + h), chkmax(yMax, v + h);
    }
    ll h = max(xMax - xMin + 1, yMax - yMin + 1) / 2;
    cout << (xMax + xMin) / 2 << " " <<  (yMax + yMin) / 2 <<  " " << h << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
