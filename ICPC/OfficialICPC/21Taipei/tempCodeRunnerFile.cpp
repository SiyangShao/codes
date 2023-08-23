#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

ll a[102][102];
void solve() {
  ll m, n; cin >> n >> m;
  FOR(i, 0, n + 1) FOR(j, 0, m + 1) a[i][j] = 0;
  FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
  ll s, f, r; cin >> s >> f >> r;
  FOR(i, 1, n) FOR(j, 1, m) {
    vector<ll> dirs = {a[i - 1][j], a[i][j + 1], a[i + 1][j], a[i][j - 1]}; 
    bool ok = false;
    FOR(i, 0, 3) if (dirs[i] == f && dirs[(i + 1) % 4] == r && a[i][j] == s) ok = true;
    if (ok) cout << i - 1 << " " << j - 1 << '\n';
  }
  cout.flush();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
