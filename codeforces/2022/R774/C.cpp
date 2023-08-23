#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 1e12 + 7;
vector<ll> frac;
ll ans;
void init() {
    frac.push_back(1);
    for (ll i = 1; i * frac[i - 1] < N; ++i) {
        frac.push_back(i * frac[i - 1]);
    }
}
inline ll judge(ll x) {
    ll ans = 0;
    while (x) {
        if (x & 1) {
            ans++;
        }
        x >>= 1;
    }
    return ans;
}
void dfs(int i, ll n, ll add) {
    if (i == 0) {
        ans = min(ans, judge(n) + add);
        return;
    }
    if (n >= frac[i])
        dfs(i - 1, n - frac[i], add + 1);
    dfs(i - 1, n, add);
}
void solve() {
    ll n;
    cin >> n;
    ans = judge(n);
    auto cnt = frac.size() - 1;
    for (int i = 0; i < frac.size(); ++i) {
        if (frac[i] > n) {
            cnt = i - 1;
            break;
        }
    }
    dfs(cnt, n, 0);
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    // cout << judge(N);
}