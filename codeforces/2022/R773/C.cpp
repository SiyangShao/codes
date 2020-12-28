#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    unordered_map<ll, ll> vis;
    for (auto &i : a) {
        cin >> i;
        vis[i]++;
    }
    sort(a.begin(), a.end());
    ll cnt = 0;
    for (auto i : a) {
        if (vis[i] == 0)
            continue;
        vis[i]--;
        if (vis[i * x] == 0) {
            cnt++;
        } else {
            vis[i * x]--;
        }
    }
    cout << cnt << "\n";
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