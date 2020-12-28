#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 310;
ll d[N][N];
vector<tuple<ll, ll, ll>> E;
ll n, m;
void solve() {
    memset(d, 0x3f, sizeof(d));
    cin >> n >> m;
    E.resize(m);
    for(auto &[u,v,w] : E){
        cin >> u >> v >> w;
    }
    for (auto &[u, v, w] : E) {
        d[u][v] = w;
        d[v][u] = w;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll ans = 0;
    for (auto &[u, v, w] : E) {
        bool flag = false;
        for (int i = 1; i <= n; ++i) {
            if (d[u][i] + d[i][v] <= w) {
                flag = true;
            }
        }
        if (flag)
            ans++;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}