#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = dp[i - 1] + a[i];
    }
    vector<ll> sum(n + 1, INT_MIN);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            sum[i - j] = max(sum[i - j], dp[i] - dp[j]);
        }
    }
    for (int i = 0; i <= n; ++i) {
        ll ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = max(ans, sum[j] + min(j, i) * x);
        }
        cout << ans << " ";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}