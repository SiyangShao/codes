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
    string p, q; cin >> p >> q;
    ll pv = stoll(p), qv = stoll(q);
    ll g = __gcd(pv, qv); pv /= g, qv /= g;
    for (int i = 0; i < 524287; i++) {
        // 1. generate u
        vl drop(10);
        string u;
        FOR(t, 0, min(18, (signed)p.size() - 1)) {
            if ((1ll << t) & i) u = u + p[t];
            else drop[p[t] - '0']++;
        }
        // 2. check u feasibility
        ll uv = stoll(u); 
        if (uv % pv != 0 || uv == 0) continue;
        // 3. generate v
        ll vv = uv / pv * qv;
        string v = to_string(vv);
        // match v to check v feasibility
        if (v.size() > q.size()) continue;
        string vpop = v, org = q;
        while (!vpop.empty() && !org.empty()) {
            while (!vpop.empty() && !org.empty() && org.back() != vpop.back()) drop[org.back() - '0']--, org.pop_back();
            if (vpop.empty() || org.empty()) break;
            vpop.pop_back(); org.pop_back();
        }
        bool ok = true;
        FOR(i, 0, 9) if (drop[i] != 0) ok = false;
        if (vpop.empty() && ok) 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
