#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;
void solve() {
    ll n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<pair<ll, ll>> a(q);
    for (auto &[x, y] : a)
        cin >> x >> y;
    unordered_map<ll, ll> row, col;
    ll cnt = 1;
    for (auto i = a.rbegin(); i < a.rend(); ++i) {
        bool flag = false;
        if (row[i->first] == 0) {
            flag = true;
            row[i->first] = 1;
            n--;
        }
        if (col[i->second] == 0) {
            flag = true;
            col[i->second] = 1;
            m--;
        }
        if (flag) {
            cnt = cnt * k % MOD;
        }
        if (!n || !m) {
            break;
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