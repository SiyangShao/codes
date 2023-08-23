#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c;
vector<ll> vis, cnt, a;
void solve() {
    cin >> n >> c;
    vis.assign(c + 1, 0);
    cnt.assign(c + 1, 0);
    a.resize(n);
    for (auto &i : a) {
        cin >> i;
        vis[i] = 1;
        cnt[i]++;
    }
    for (int i = 1; i <= c; ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (ll i = 1; i <= c; ++i) {
        if (vis[i] == 1)
            for (ll j = 1; i * j <= c; ++j) {
                ll l = i * j, r = min(i * (j + 1), c + 1);
                if (cnt[r - 1] - cnt[l - 1] > 0 && vis[j] != 1) {
                    cout << "No\n";
                    return;
                }
            }
    }
    cout << "Yes\n";
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