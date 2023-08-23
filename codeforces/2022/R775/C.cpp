#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 1e5 + 7;
ll n, m;
vector<ll> X[N], Y[N];
vector<ll> dp(N);
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int col;
            cin >> col;
            X[col].emplace_back(i);
            Y[col].emplace_back(j);
        }
    }
    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        if (X[i].empty()) {
            continue;
        }

        int nn = X[i].size();
        // cout << "\n";
        // for (int j = 0; j < nn; ++j) {
        //     cout << X[i][j] << " " << Y[i][j] << "\n";
        // }
        sort(X[i].begin(), X[i].end());
        sort(Y[i].begin(), Y[i].end());
        dp[0] = 0;
        for (int j = 1; j < nn; ++j) {
            dp[j] =
                (X[i][j] - X[i][j - 1] + Y[i][j] - Y[i][j - 1]) * j + dp[j - 1];
            ans += dp[j];
        }
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