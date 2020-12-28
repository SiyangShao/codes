#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    priority_queue<ll> q, bfs;
    ll ans = 0;
    for (auto &i : a) {
        cin >> i;
        ans += i;
        mp[i]++;
        q.push(i);
    }
    bfs.push(ans);
    while (!bfs.empty()) {
        auto cur = bfs.top();
        bfs.pop();
        if (cur == q.top()) {
            q.pop();
        } else if (cur < q.top()) {
            cout << "NO\n";
            return;
        } else {
            auto l = cur / 2;
            auto r = cur - l;
            bfs.push(r);
            bfs.push(l);
        }
    }
    cout << "YES\n";
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