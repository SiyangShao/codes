#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline bool judge(int x, int bs, unordered_map<ll, int> &vis) {
    int tmp = 1;
    while (x >= tmp) {
        if (vis[x] != 0 || vis[x / tmp] != 0)
            return false;
        tmp *= bs;
    }
    return true;
}
void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    unordered_map<ll, int> vis;
    for (auto &i : a) {
        cin >> i;
        vis[i] = 1;
    }
    sort(a.begin(), a.end());
    // judge for any x,y in a, x > y, x/y is in c or not
    if (a[0] != 1) {
        cout << "No\n";
        return;
    }
    ll m = -1;
    for (auto i : a) {
        if (i != 1) {
            m = i;
            break;
        }
    }
    if (m == -1) {
        cout << "Yes\n";
        return;
    }
    for (auto i : a) {
        if (!judge(i, m, vis)) {
            cout << "No\n";
            return;
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