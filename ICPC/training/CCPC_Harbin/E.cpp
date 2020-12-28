#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    if (a[0] != 1) {
        for (auto i : a) {
            if (i != 0) {
                cout << "-1\n";
                return;
            }
        }
        cout << 1 << "\n";
        return;
    }
    ll ans = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1] * 2) {
            ans = a[i - 1] * 2 - a[i];
            break;
        }
    }
    if (ans <= 0) {
        cout << "-1\n";
    } else {
        ll tmp = 1 % ans;
        for (int i = 0; i < n; ++i) {
            if (tmp % ans != a[i]) {
                cout << "-1\n";
                return;
            }
            tmp = (tmp * 2ll) % ans;
        }
        cout << ans << "\n";
    }
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