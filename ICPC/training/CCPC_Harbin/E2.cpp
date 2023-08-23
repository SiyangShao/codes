#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef vector<ll> vl;
#define eb emplace_back
#define all0(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define ROF(i, a, b) for(ll i=(a); i>=(b); i--)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

void solve(){
    ll n; cin >> n;
    vl a(n + 1); FOR(i, 1, n) cin >> a[i];
    bool fullZero = true;
    FOR(i, 1, n) if (a[i] != 0) fullZero = false;
    if (fullZero) cout << 1 << endl;
    else {
        ll gcd = -1; ll mb = 2;
        FOR(i, 2, n) {
            if (a[i - 1] * 2 != a[i]) {
                if (a[i - 1] * 2 < a[i]) {
                    cout << -1 << endl;
                    return;
                }
                // mod number
                // std::gcd
                if (gcd == -1) gcd = a[i - 1] * 2 - a[i];
                else gcd == __gcd(gcd, a[i - 1] * 2 - a[i]);
                chkmax(mb, a[i] + 1);
            } else chkmax(mb, a[i] + 1);
        }
        ll cand = (gcd >= mb); // gcd himself
        FOR(i, 2, sqrt(gcd)) if (gcd % i == 0){
            if (i >= mb) cand++;
            if (gcd / i >= mb && gcd / i != i) cand++;
        }
        if (cand != 1) cout << -1 << endl;
        else cout << gcd << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
