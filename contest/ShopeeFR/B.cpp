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
    ll dp[22][5002]; // maximum largest length possible with that diff
    void solve(){
        ll n; cin >> n;
        vl a(n + 1); FOR(i, 1, n) cin >> a[i];
        FOR(i, 0, n) FOR(pdiff, 0, 5000) dp[i][pdiff] = -1e16;
        dp[0][0] = 0;
        FOR(i, 0, n - 1) FOR(pdiff, 0, 5000) {
            // expand current answer
            chkmax(dp[i + 1][pdiff], dp[i][pdiff]);
            if (dp[i][pdiff] < 0) continue; // only if it's possible
            ll large = dp[i][pdiff], small = large - pdiff;
     
            ll t1 = small + a[i + 1], t2 = large;
            chkmax(dp[i + 1][abs(t1 - t2)], max(t1, t2));
     
            t1 = small, t2 = large + a[i + 1];
            chkmax(dp[i + 1][abs(t1 - t2)], max(t1, t2));
        }
        if (dp[n][0] >= 0) cout << dp[n][0] << endl;
        else cout << 0 << endl;
    }
     
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
     
        ll T = 1;
        // cin >> T;
        while (T--) solve();
        return 0;
    }