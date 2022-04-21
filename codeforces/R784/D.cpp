#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll R = 0, B = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            if ((R == 0 && B != 0) || (R != 0 && B == 0)) {
                cout << "NO\n";
                return;
            }
            R = 0, B = 0;
        } else {
            if (s[i] == 'R')
                R++;
            else
                B++;
        }
    }
    if ((R == 0 && B != 0) || (R != 0 && B == 0)) {
        cout << "NO\n";
        return;
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