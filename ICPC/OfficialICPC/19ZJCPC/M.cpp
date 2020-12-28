#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

bool a[1002][1002];
bool hasWhiteCross[1002][1002];
ll pf[1002][1002];
ll n, m; 

ll sum(ll u, ll v, ll w, ll h) {
    // u, v must at topleft, w, h must at bottomright
    if (u > w || v > h) return 0;
    return pf[w][h] - pf[w][v - 1] - pf[u - 1][h] + pf[u - 1][v - 1];
}

inline bool valid(ll x, ll y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

inline bool hasCross(ll x, ll y) {
    return 
        valid(x - 1, y - 1) && valid(x + 2, y + 2) && 
        a[x - 1][y - 1] && a[x - 1][y + 2] && a[x + 2][y - 1] && a[x + 2][y + 2] && 
        sum(x - 1, y - 1, x + 2, y + 2) == 4;
}

void solve(){
    cin >> n >> m;
    FOR(i, 1, n) {
        string s; cin >> s;
        FOR(j, 1, m) a[i][j] = s[j - 1] == '#';
    }

    FOR(i, 1, n) FOR(j, 1, m) pf[i][j] = pf[i - 1][j] + pf[i][j - 1] + a[i][j] - pf[i - 1][j - 1];
    FOR(i, 1, n) FOR(j, 1, m) hasWhiteCross[i][j] = hasCross(i, j); // memo

    // 1. greedily match C type
    ll cntC = 0;
    FOR(x, 1, n) FOR(y, 1, m) if (hasWhiteCross[x][y]) {
        if (valid(x + 7, y) && hasWhiteCross[x + 7][y]) hasWhiteCross[x][y] = hasWhiteCross[x + 7][y] = false, cntC++;
        else if (valid(x, y + 7) && hasWhiteCross[x][y + 7]) hasWhiteCross[x][y + 7] = hasWhiteCross[x][y] = false, cntC++;
    }
    // 2. rest is triv
    ll remBlack = sum(1, 1, n, m) - cntC * 146;
    assert(remBlack >= 0 && remBlack % 100 == 0);
    ll cntS = remBlack / 100;

    cout << cntC << " " << cntS << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
