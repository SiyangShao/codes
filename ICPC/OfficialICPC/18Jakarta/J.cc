#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

string s[16];
vector<string> subStrs[16];
ll dp[16][33000];

#define fullmask(x) ((1ll << (x)) - 1)

void solve(){
    ll n; cin >> n;
    FOR(i, 1, n) cin >> s[i];

    // 1. generate every substring: o(n * 2^n * n)
    // 2. sort: O(n * (2^n * log (2^n) * n)) = O(n^3 * 2^n) => 1e8
    FOR(i, 1, n) {
        FOR(msk, 0, fullmask(s[i].length())) {
            string ts;
            for (ll t = 0; t < s[i].length(); t++) if ((1ll << t) & msk) ts += s[i][t];
            subStrs[i].emplace_back(ts);
        }
        sort(subStrs[i].begin(), subStrs[i].end());
    }
    
    // 3. update DP
    FOR(i, 0, subStrs[n].size() - 1) dp[n][i] = subStrs[n][i].length();
    for (ll i = n; i >= 2; --i) {
        auto& prevStrs = subStrs[i - 1];
        vector<ll> prop(prevStrs.size()); // temp prop array

        FOR(ssIdx, 0, subStrs[i].size() - 1) { // for each of current substr
            auto pos = upper_bound(prevStrs.begin(), prevStrs.end(), subStrs[i][ssIdx]);
            if (pos != prevStrs.begin()) {
                ll idx = pos - prevStrs.begin() - 1;
                chkmax(prop[idx], dp[i][ssIdx]);
            }
        }

        ll tMx = 0;
        for (ll i = prevStrs.size() - 1; i >= 0; --i) chkmax(tMx, prop[i]), chkmax(prop[i], tMx);
        FOR(t, 0, prevStrs.size() - 1) if (prop[t] != 0) dp[i - 1][t] = prop[t] + subStrs[i - 1][t].length();
    }

    // 4. output
    ll ans = 0;
    FOR(i, 1, subStrs[1].size() - 1) chkmax(ans, dp[1][i]);
    cout << (ans == 0 ? -1 : ans) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}