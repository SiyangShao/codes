#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e5 + 5, S = 100;
ll n, ans;
array<ll, N> a;
unordered_map<ll, ll> cnt;
array<unordered_map<ll, ll>, N> dp;
void solve() {
    for (int d = 0; d <= S; d++) {
        cnt.clear();
        for (int i = 0; i < n; i++) {
            ans = max(ans, ++cnt[a[i] - i * d]);
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i].clear();
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j - i <= S && j < n; j++) {
            if ((a[j] - a[i]) % (j - i) == 0) {
                int d = (a[j] - a[i]) / (j - i);
                if (d <= S) {
                    continue;
                }
                dp[j][d] = max(dp[j][d], dp[i][d] + 1);
                ans = max(ans, dp[j][d] + 1);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve();
    reverse(a.begin(), a.begin() + n);
    solve();
    cout << n - ans << "\n";
}