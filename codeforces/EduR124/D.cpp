#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> vis, tran, have;
constexpr ll N = 1e6 + 7;
constexpr ll NN = 1e6;
inline ll cal(pair<ll, ll> point) { return point.first * N + point.second; }
inline ll num(pair<ll, ll> point) { return tran[cal(point)]; }
int n;
vector<pair<ll, ll>> a;
vector<pair<ll, pair<ll, ll>>> dp;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
inline bool judge(pair<ll, ll> point) {
    for (int i = 0; i < 4; ++i) {
        auto nxt = make_pair(point.first + dx[i], point.second + dy[i]);
        if (vis[cal(nxt)] == 0) {
            dp[num(point)] = {1, nxt};
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n;
    a.resize(n);
    dp.resize(n);
    int cnt = 0;
    for (auto &[x, y] : a) {
        cin >> x >> y;
        vis[cal({x,y})] = 1;
        tran[cal({x, y})] = cnt;
        cnt++;
    }
    queue<pair<ll, ll>> Q;
    for (auto p : a) {
        if (judge(p)) {
            have[num(p)] = 1;
            Q.push(p);
        }
    }
    // cout << "\n";
    while (!Q.empty()) {
        auto p = Q.front();
        // cout << p.first << " " << p.second << " " << dp[num(p)].second.first
        //      << " " << dp[num(p)].second.second << "\n";
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            auto nxt = make_pair(p.first + dx[i], p.second + dy[i]);
            if (vis[cal(nxt)] == 1 && have[num(nxt)] == 0) {
                Q.push(nxt);
                have[num(nxt)] = 1;
                dp[num(nxt)] = {dp[num(p)].first + 1, dp[num(p)].second};
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dp[i].second.first << " " << dp[i].second.second << "\n";
    }
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