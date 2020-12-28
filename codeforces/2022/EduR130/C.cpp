#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    string s, t;
    cin >> n >> s >> t;
    ll a = 0, b = 0, c = 0;
    for (auto i : s) {
        if (i == 'a')
            a++;
        if (i == 'b')
            b++;
        if (i == 'c')
            c++;
    }
    for (auto i : t) {
        if (i == 'a')
            a--;
        if (i == 'b')
            b--;
        if (i == 'c')
            c--;
    }
    if (a != 0 || b != 0 || c != 0) {
        cout << "NO\n";
        return;
    }
    vector<ll> L, R;
    L.clear(), R.clear();
    for (ll i = 0; i < n; ++i) {
        if (s[i] != 'b') {
            if (s[i] == 'a') {
                L.emplace_back(1);
            } else {
                L.emplace_back(2);
            }
        }
        if (t[i] != 'b') {
            if (t[i] == 'a') {
                R.emplace_back(1);
            } else {
                R.emplace_back(2);
            }
        }
    }
    if (L != R) {
        cout << "NO\n";
        return;
    }
    L.clear(), R.clear();
    ll l = 0, r = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'c') {
            l++;
        } else if (s[i] == 'b') {
            L.emplace_back(l);
        }
        if (t[i] == 'c') {
            r++;
        } else if (t[i] == 'b') {
            R.emplace_back(r);
        }
    }
    for (ll i = 0; i < L.size(); ++i) {
        if (L[i] > R[i]) {
            cout << "NO\n";
            return;
        }
        // cout << L[i] << " " << R[i] << "\n";
    }
    L.clear(), R.clear();
    l = 0, r = 0;
    for (ll i = n - 1; i >= 0; --i) {
        if (s[i] == 'a') {
            l++;
        } else if (s[i] == 'b') {
            L.emplace_back(l);
        }
        if (t[i] == 'a') {
            r++;
        } else if (t[i] == 'b') {
            R.emplace_back(r);
        }
    }
    for (ll i = 0; i < L.size(); ++i) {
        if (L[i] > R[i]) {
            cout << "NO\n";
            return;
            // cout << L[i] << " " << R[i] << ": ";
        }
    }
    cout << "YES\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}