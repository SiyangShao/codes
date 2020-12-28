#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
#define eb emplace_back
#define all0(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define ROF(i, a, b) for (ll i = (a); i >= (b); i--)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
/**
 * @brief By pity Hero
 * 
 */
void solve() {
    ll n;
    cin >> n;
    vector<string> s;
    map<char, ll> f;
    FOR(i, 1, n) {
        string t;
        cin >> t;
        s.eb(t);
        f[t[0]]++;
    }
    FOR(i, 1, n) {
        map<char, ll> tf;
        for (auto e : s[i - 1])
            tf[e]++;
        bool bad = false;
        for (auto [u, v] : tf)
            if (f[u] == 0)
                bad = true;
        if (!bad) {
            cout << "Y" << endl;
            return;
        }
    }
    cout << "N" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
