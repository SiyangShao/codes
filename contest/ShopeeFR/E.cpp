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

void solve(){
    map<string ,ll> balance;
    ll n, t; cin >> n >> t;
    FOR(i, 1, n) {
        string t; cin >> t;
        cin >> balance[t];
    }
    FOR(i, 1, t) {
        string u1, u2; cin >> u1 >> u2;
        ll val; cin >> val;
        if (val > balance[u1]) continue;
        else balance[u1] -= val, balance[u2] += val;
    }
    for (auto [u, v]: balance) cout << u << " " << v << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
