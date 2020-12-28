#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    ll LA = INT_MAX, LB = INT_MAX;
    ll RA = INT_MAX, RB = INT_MAX;
    for (int i = 0; i < n; ++i) {
        LA = min(LA, abs(b[i] - a[0]));
        LB = min(LB, abs(a[i] - b[0]));
        RA = min(RA, abs(b[i] - a[n - 1]));
        RB = min(RB, abs(a[i] - b[n - 1]));
    }
    ll ans = min(abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]),
                 abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
    ans = min(ans, LA + RB + abs(a[n - 1] - b[0]));
    ans = min(ans, LB + RA + abs(a[0] - b[n - 1]));
    ans = min(ans, LA + LB + RA + RB);
    ans = min(ans, LA + LB + abs(a[n - 1] - b[n - 1]));
    ans = min(ans, RA + RB + abs(a[0] - b[0]));
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