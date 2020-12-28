#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(...) (VA_ARGS)

void solve() {
    ll x; cin >> x;
    cout << 1 << '\n';
    if (x == 1) {
        cout << x * 2 << '\n';
        for (ll i = 1; i <= x * 2; ++i) cout << 1 << " ";
        cout << '\n';
    } else if (x != 25) {
        cout << 2 * x + 2 << '\n';
        for (ll i = 1; i <= 2 * x; ++i) cout << 1 << " ";
        cout << 1 << " " << x << '\n';
    } else {
        cout << 2 * x << '\n';
        for (ll i = 1; i <= 2 * x; ++i) cout << 5 << " ";
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll TT = 1;
    // cin >> TT;
    for (ll T = 1; T <= TT; ++T) solve();

    return 0;
}