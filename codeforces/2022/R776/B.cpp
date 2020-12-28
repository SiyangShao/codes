#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll l, r, a;
    cin >> l >> r >> a;
    ll L = l / a, R = r / a;
    ll ans = R + r % a;
    if (L != R) {
        ans = max(ans, R - 1 + a - 1);
    }
    cout << ans << "\n";
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