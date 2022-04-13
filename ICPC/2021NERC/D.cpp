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
    string s, t; cin >> s >> t;
    // deletion is in order. suppose t have f[i] ith character, then it must be the last of them.
    map<char, ll> fs, ft;
    for (auto e: s) fs[e] ++;
    for (auto e: t) ft[e] ++;
    deque<bool> del(s.size());
    FOR(i, 0, s.size() - 1) {
        if (fs[s[i]] > ft[s[i]]) del[i] = true, fs[s[i]]--;
    }
    string ns;
    FOR(i, 0, s.size() - 1) if (!del[i]) ns = ns + s[i];
    cout << (ns == t ? "YES" : "NO") << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}