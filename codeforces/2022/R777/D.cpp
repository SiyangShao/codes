#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline bool is_prime(ll x) {
    if (x < 2)
        return true;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
void solve() {
    ll x, d;
    cin >> x >> d;
    ll cnt = 0;
    while (x % d == 0) {
        x /= d;
        cnt++;
    }
    if (cnt < 2) {
        cout << "NO\n";
        return;
    }
    if (cnt == 2) {
        if (is_prime(x)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        return;
    }
    if (is_prime(x)) {
        if (is_prime(d)) {
            cout << "NO\n";
        } else {
            if (cnt > 3) {
                cout << "YES\n";
            } else {
                if (d % x == 0) {
                    ll tmp = d / x;
                    if (x * x % d == 0 && is_prime(tmp)) {
                        cout << "NO\n";
                    } else {
                        cout << "YES\n";
                    }
                } else {
                    cout << "YES\n";
                }
            }
        }
    } else {
        cout << "YES\n";
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